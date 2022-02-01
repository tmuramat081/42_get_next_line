#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	input_by_line(int fd, char **mem_line)
{	
	char 		*buff;
	char		*mem_cpy;
	int			flag;
	size_t		i;

	mem_cpy = ft_strdup(*mem_line);
	buff = malloc(BUFFER_SIZE + 1);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		flag = read(fd, &buff[i], 1);
		if (!flag)
		{
			buff = NULL;
			return 0;
		}
		if (buff[i] == '\n' )
		{
			buff[i + 1] = '\0';
			if (!*mem_line)
				*mem_line = ft_strdup(buff);
			else
			*mem_line = ft_strjoin(mem_cpy, buff);
			free(buff);
			return (0);
		}
		i++;
	}
	buff[i] = '\0';
	*mem_line = ft_strjoin(mem_cpy, buff);
	free (buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*mem_line;
	int				flag;

	mem_line = malloc(sizeof(char) * 1);
	mem_line[0] = '\0';
	flag = 1;
	while (flag)
		flag = input_by_line(fd, &mem_line);
	return (mem_line);
}
