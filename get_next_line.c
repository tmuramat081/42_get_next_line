#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*read_buffer(int fd)
{	
	char	*buff;
	ssize_t	buf_size;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buf_size = read(fd, buff, BUFFER_SIZE);
	if (buf_size < 1)
		return (NULL);
	buff[buf_size] = '\0';
	return (buff);
}

void	save_memory(char *buff, t_line	*memory)
{
	char	*tmp_str;

	tmp_str = ft_strjoin(memory->str, buff);
	free(memory->str);
	memory->str = NULL;
	memory->str = tmp_str;
	memory->ptr_nl = ft_strchr(memory->str, '\n');
	
}

char	*output_one_line(t_line *memory)
{
	char 	*ret_line;
	char	*tmp_memory;

	tmp_memory = ft_strdup(memory->ptr_nl + 1);
	*(memory->ptr_nl + 1) = '\0';
	ret_line = ft_strdup(memory->str);
	free(memory->str);
	memory->str = NULL;
	memory->str = tmp_memory;
	memory->ptr_nl = ft_strchr(memory->str, '\n');
	return(ret_line);
}

char	*get_next_line(int fd)
{
	static t_line	memory;
	char			*buff;
	char			*ret_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!memory.str)
		memory.str = strdup("");
	while (!memory.ptr_nl)
	{
		buff = read_buffer(fd);
		if (!buff)
			return(NULL);
		save_memory(buff, &memory);			
	}
	ret_line = output_one_line(&memory);
	return (ret_line);
}
