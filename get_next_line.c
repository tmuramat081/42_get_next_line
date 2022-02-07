#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	read_buffer(int fd, char *buff, t_line *memory)
{	
	ssize_t	buf_size;
	char	*tmp_str;

	buf_size = read(fd, buff, BUFFER_SIZE);
	if (buf_size == -1)
	{
		memory->sts = ERROR;
		return ;
	}
	else if (buf_size == 0)
		memory->sts = END_OF_FILE;
	buff[buf_size] = '\0';
	tmp_str = ft_strjoin(memory->str, buff);
	free(memory->str);
	memory->str = tmp_str;
	memory->ptr_nl = ft_strchr(memory->str, '\n');
	if (memory->ptr_nl)
		memory->sts = RETURN;
}

char	*output_one_line(t_line *memory)
{
	char 	*ret_line;
	char	*tmp_memory;

	if (memory->sts == END_OF_FILE && !memory->ptr_nl)
	{
		ret_line = ft_strdup(memory->str);
		free(memory->str);
		return (ret_line);
	}
	ret_line = ft_substr(memory->str, 0, memory->ptr_nl - memory->str + 1);
	tmp_memory = ft_strdup(memory->ptr_nl + 1);
	free(memory->str);
	memory->str = tmp_memory;
	memory->ptr_nl = ft_strchr(memory->str, '\n');
	if (!memory->ptr_nl && memory->sts == RETURN)
		memory->sts = CONTINUE;
	return(ret_line);
}

char	*get_next_line(int fd)
{
	static t_line	memory;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || memory.sts == END_OF_FILE)
		return (NULL);
	if (!memory.str)
		memory.str = ft_strdup("");
	while (memory.sts == CONTINUE)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		read_buffer(fd, buff, &memory);
		if (memory.sts == ERROR)
		{
			free(buff);
			return(NULL);
		}
		free(buff);
	}
	if (memory.sts == END_OF_FILE && !memory.ptr_nl && !ft_strlen(memory.str))
		return (NULL);
	return (output_one_line(&memory));
}
