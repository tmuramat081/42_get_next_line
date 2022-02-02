#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

t_line	input_by_line(int fd, char *buff)
{	
	t_line	input;	
	char 	*p;
	size_t	len_read;

	len_read = read(fd, buff, BUFFER_SIZE);
	if (len_read < 1)
	{
		input.ret = ft_strdup(buff);
		input.mem = NULL;
		return (input);
	}
	buff[len_read] = '\0';
	p = memchr(buff, '\n', len_read);
	if (p)
	{
		input.ret = ft_substr(buff, 0, p - buff);
		input.mem = ft_strjoin(buff, p + 1);
	}
	else
	{
		input.ret = NULL;
		input.mem = ft_strjoin(buff, buff);
	}
	return (input);
}

char *output_by_line(char **mem_line, t_line input)
{
	char *cpy_line;

	if (!*mem_line)
		*mem_line = input.mem;
	cpy_line = strdup(*mem_line);
	free(*mem_line);
	*mem_line = NULL;
	*mem_line = ft_strjoin(cpy_line, input.mem);
	return (input.ret);
}

char	*get_next_line(fd)
{
	static char		*mem_line;
	char 			*buff;
	t_line			input;
	char			*output;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	input = input_by_line(fd, buff);
	output = output_by_line(&mem_line, input);
	free(buff);
	if (!output)
		get_next_line(fd);
	return (output);
}
