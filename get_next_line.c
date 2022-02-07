#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	read_buffer(int fd, t_line *memory)
{	
	char	buff[BUFFER_SIZE + 1];
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
	memory->str = NULL;
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
		return (memory->str);
	ret_line = ft_substr(memory->str, 0, memory->ptr_nl - memory->str + 1);
	tmp_memory = ft_strdup(memory->ptr_nl + 1);
	free(memory->str);
	memory->str = NULL;
	memory->str = tmp_memory;
	memory->ptr_nl = ft_strchr(memory->str, '\n');
	if (!memory->ptr_nl)
		memory->sts = CONTINUE;
	return(ret_line);
}

char	*get_next_line(int fd)
{
	static t_line	memory;
	char			*ret_line;

	if (fd < 0 || BUFFER_SIZE < 0 || INT_MAX <= BUFFER_SIZE)
		return (NULL);
	if (memory.sts == END_OF_FILE)
		return (NULL);
	if (!memory.str)
		memory.str = strdup("");
	while (memory.sts == CONTINUE)
	{
		read_buffer(fd, &memory);
		if (memory.sts == ERROR)
			return(NULL);
		else if (memory.sts == END_OF_FILE)
			break ;
	}
	ret_line = output_one_line(&memory);
	return (ret_line);
}
