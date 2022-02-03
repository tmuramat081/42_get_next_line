#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

t_line	input_by_line(int fd, char *buff)
{	
	t_line	input;	
	char 	*ptr;
	int		size_read;

	size_read = read(fd, buff, BUFFER_SIZE);
	if (size_read == - 1)
		input.sts = ERROR;
	else
	{
		buff[size_read] = '\0';
		ptr = strchr(buff, '\n');
		if (size_read == 0)
			input.sts = END_OF_FILE;
		else if (ptr)
		{
			input.ret = ft_substr(buff, 0, ptr - buff + 1);
			input.mem = ft_substr(buff, ptr - buff + 1, size_read);
			input.sts = RETURN;
		}
		else
		{
			input.mem = ft_substr(buff, 0, size_read);
			input.sts = CONTINUE;
		}
	}
	return (input);
}

char *output_by_line(t_line input)
{
	static char 	*memory;
	char			*tmp;
	char 			*ret;

	ret = NULL;
	if (!memory)
		tmp = strdup("");
	else
		tmp = strdup(memory);
	free(memory);
	if (input.sts == END_OF_FILE)
	{
		ret = ft_strdup(tmp);
//		printf("[%s]\n", ret);
	}
	else if (input.sts == RETURN)
	{
		ret = ft_strjoin(tmp, input.ret);
		memory = ft_strdup(input.mem);
	}
	else if (input.sts == CONTINUE)
 		memory = ft_strjoin(tmp, input.mem);
//	printf("--%s--\n", memory);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char 			*buff;
	t_line			input;
	char			*output;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if(!buff)
		return (NULL);
	input = input_by_line(fd, buff);
//	printf("\n[ret:%s]", input.ret);
//	printf("\n[mem:%s]", input.mem);
	free(buff);
	if (input.sts == ERROR || input.sts == END_OF_FILE)
		return (NULL);
	output = output_by_line(input);
	if(!output)
		get_next_line(fd);
	return (output);
}
