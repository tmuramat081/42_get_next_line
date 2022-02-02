#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

t_line	input_by_line(int fd, char *buff)
{	
	t_line	input;	
	char 	*ptr;
	int		len_read;

	len_read = read(fd, buff, BUFFER_SIZE);
	if (len_read == -1)
	{
		input.ret = NULL;
		input.mem = NULL;
		return (input);
	}
	buff[len_read] = '\0';
	ptr = memchr(buff, '\n', len_read);
	if (ptr)
	{
		input.ret = ft_substr(buff, 0, ptr - buff + 1);
		input.mem = ft_substr(buff, ptr - buff + 1, len_read);
	}
	else
	{
		input.ret = NULL;
		input.mem = ft_substr(buff, 0, len_read);
	}
	return (input);
}

char *output_by_line(t_line input)
{
	static char	mem_line[BUFFER_SIZE];
	char 		*ret;	
	
	ret = ft_strjoin(mem_line, input.ret);
	bzero(mem_line, BUFFER_SIZE);
	ft_strlcat(mem_line, input.mem, BUFFER_SIZE);
//	printf("[mem_line]%s\n", mem_line);
	return (ret);
}

char	*get_next_line(int fd)
{
	char 			*buff;
	t_line			input;
	char			*output;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buff)
		return (NULL);
	input = input_by_line(fd, buff);
	if (!input.ret && !input.mem)
		return (NULL);
	free(buff);
	buff = NULL;
//	printf("[ret]%s\n", input.ret);
//	printf("[mem]%s\n", input.mem);
	output = output_by_line(input);
	if (!output)
		get_next_line(fd);
	return (output);
}
