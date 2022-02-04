#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*read_buffer(int fd, char *cpy_memory)
{	
	char	*buff;
	ssize_t	buf_size;
	char	*input;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buf_size = read(fd, buff, BUFFER_SIZE);
	if (buf_size < 1)
		return (NULL);
	buff[buf_size] = '\0';
	input = ft_strjoin(cpy_memory, buff);
	free(buff);
	buff = NULL;
	return (input);
}

char	*output_by_line(char *input, char **memory)
{
	char 	*ptr;
	char 	*ret_line;

	ret_line = NULL;
	ptr = strchr(input, '\n');
	if (ptr)
	{
		*memory = ft_strdup(ptr + 1);
		*(ptr + 1) = '\0';
		ret_line = ft_strdup(input);
	}
	free(input);
	return(ret_line);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*cpy_memory;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!memory)
		memory = strdup("");
	cpy_memory = strdup(memory);
	free(memory);
	memory = NULL;
	if(!strchr(cpy_memory, '\n'))
	{
		cpy_memory = read_buffer(fd, cpy_memory);
		if (cpy_memory == NULL)
			return (NULL);
	}
	else
		ret_line = NULL;
	ret_line = output_by_line(cpy_memory, &memory);
	if (!ret_line)
		get_next_line(fd);
	return (ret_line);
}
