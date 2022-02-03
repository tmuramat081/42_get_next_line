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
	else if (size_read == 0)
		input.sts = END_OF_FILE;
	else
	{
		buff[size_read] = '\0';
		ptr = strchr(buff, '\n');
		if (ptr)
		{
			input.ret = ft_substr(buff, 0, ptr - buff + 1);
			input.mem = ft_substr(buff, ptr - buff + 1, size_read);
			input.sts = RETURN;
		}
		else
		{
			input.ret = NULL;
			input.mem = ft_substr(buff, 0, size_read);
			input.sts = CONTINUE;
		}
	}
	return (input);
}

char *output_by_line(t_line input)
{
	static char 	cache_memory[BUFFER_SIZE];
	char 			*ret;

	ret = NULL;
	if (input.sts == END_OF_FILE)
	{
		ret = ft_strjoin(cache_memory, input.ret);
	}
	if (input.sts == RETURN)
	{	
		ret = ft_strjoin(cache_memory, input.ret);
		bzero(cache_memory, BUFFER_SIZE);
		ft_strlcat(cache_memory, input.mem, BUFFER_SIZE);
	}
	else if (input.sts == CONTINUE)
	{
		ret = NULL;
		ft_strlcat(cache_memory, input.mem, BUFFER_SIZE);
	}
//	printf("--%s--\n", cache_memory);
	return (ret);
}

char	*get_next_line(int fd)
{
	char 			*buff;
	t_line			input;
	char			*output;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if(!buff)
		return (NULL);
	input = input_by_line(fd, buff);
//	printf("[ret:%s]", input.ret);
//	printf("[mem:%s]", input.mem);
	free(buff);
	if (input.sts == ERROR || input.sts == END_OF_FILE)
		return (NULL);
	output = output_by_line(input);
	if(!output)
		get_next_line(fd);
	return (output);
}
