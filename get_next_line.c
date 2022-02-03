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
		input.nl = false;
		return (input);
	}
	buff[len_read] = '\0';
	ptr = memchr(buff, '\n', len_read);
	if (len_read == 0)
	{
		input.ret = NULL;
		input.mem = NULL;
		input.nl = true;
		return (input);
	}
	if (ptr)
	{
		input.ret = ft_substr(buff, 0, ptr - buff + 1);
		input.mem = ft_substr(buff, ptr - buff + 1, len_read);
		input.nl = true;
	}
	else
	{
		input.ret = NULL;
		input.mem = ft_substr(buff, 0, len_read);
		input.nl = false;
	}
	return (input);
}

char *output_by_line(t_line input)
{
	static	char *cache_memory;
	char 		*ret;
	
	if (!cache_memory)
	{
		cache_memory = malloc(sizeof(char) * 1);
		cache_memory[0] = '\0';
	}
	if (input.nl == true)
	{
		ret = ft_strjoin(cache_memory, input.ret);
		free(cache_memory);
		cache_memory = ft_strjoin(cache_memory, input.mem);
	}
	 if (input.nl == false)
	{
		ret = NULL;
		cache_memory = ft_strjoin(cache_memory, input.mem);
	}
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
	free(buff);
	buff = NULL;
	if (!input.ret && !input.mem && input.nl == true)
		return (NULL);
	output = output_by_line(input);
	if (input.nl == false)
		get_next_line(fd);
	else	
		return (output);
}
