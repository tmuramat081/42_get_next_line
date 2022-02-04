#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*read_buffer(int fd, char *cpy_memory)
{	
	char	*buff;
	ssize_t	buf_size;
	char	*input;

	buff = malloc(sizeof(char) * BUFFER_SIZE　+ 1);
	if (!buff)
		return (NULL);
	buf_size = read(fd, buff, BUFFER_SIZE);
	if (buf_size < 1)
		return (NULL);
	buff[buf_size] = '\0';
	*input = strjoin(cpy_memory, buff);
	free(buff);
	buff = NULL;
	return (input);
}

char	*output_by_line(char *input, char **memory)
{
	char 	*ptr;
	char 	*ret_line;

	if(ptr = strchr(input, '\0'))
	{
		ret_line = ft_substr(input, 0, ptr - input + 1);
		*memory = ft_substr(input, ptr - input + 1, strlen(input));
	}
	else
		ret_line = NULL;
	return(ret_line);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*cpy_memory;
	char		*input;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!memory)
		memory = strdup("");
	else
	{
		cpy_memory = strdup(memory);
		free(memory);
		memory = NULL;
	}
	if (!strchr(memory, '\n'))
	{
		input = read_buffer(fd, memory);
		if (input == NULL)
			return (NULL);
	}
	ret_line = output_by_line(input, &memory);
	if (!ret_line)
		get_next_line(fd);
	return (input.ret);
}
