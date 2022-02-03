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
		input.sts = ERROR;
		return (input);
	}
	buff[len_read] = '\0';
	if (len_read == 0)
	{
		input.sts = END_OF_FILE;
		return (input);
	}
	ptr = strchr(buff, '\n');
	if (ptr)
	{
		input.ret = ft_substr(buff, 0, ptr - buff + 1);
		input.mem = ft_substr(buff, ptr - buff + 1, len_read);
		input.sts = RETURN;
	}
	else
	{
		input.ret = NULL;
		input.mem = ft_substr(buff, 0, len_read);
		input.sts = CONTINUE;
	}
	return (input);
}

char *output_by_line(t_line input)
{
	static char 	*cache_memory;
	char 			*ret;

	ret = NULL;
	if (!cache_memory)
	{
		cache_memory = malloc(sizeof(char) * 1);
		cache_memory[0] = '\0';
	}
	if (input.sts == END_OF_FILE)
	{
		ret = ft_strjoin(cache_memory, input.ret);
		free(cache_memory);
		cache_memory = NULL;
	}
	else if (input.sts == RETURN)
	{	
		ret = ft_strjoin(cache_memory, input.ret);
		free(cache_memory);
		cache_memory = ft_strjoin(cache_memory, input.mem);
	}
	else if (input.sts == CONTINUE)
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
	if (input.sts == ERROR)
		return (NULL);
	else if (input.sts == END_OF_FILE)
	{
		return (NULL);
	}
	free(buff);
	output = output_by_line(input);
	if(!output)
		get_next_line(fd);
	return (output);
}
