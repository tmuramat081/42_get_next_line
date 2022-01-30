#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*input_by_line(int fd)
{	
	char 		*str;
	char 		*buff;
	size_t		i;

	buff = malloc(BUFFER_SIZE + 1);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (!read(fd, &buff[i], 1) || buff[i] == '\n' )
		{
			buff[i + 1] = '\0';
			str = ft_substr(buff, 0, i + 1);
			free(buff);
			return (str);
		}
		i++;
	}
	buff[i] = '\0';
	str = ft_substr(buff, 0, i + 1);
	free (buff);
	return (str);
}

int	output_by_line(char *mem_line, char *str)
{
	char	*ret;

	if (!mem_line)
	{
		mem_line = ft_strdup(str);
		ret = mem_line;
	}
	else
		ret = ft_strjoin(mem_line, str);
	free(str);
	str = NULL;
	return (ret);
}

char	*get_next_line(fd)
{
	static char		*mem_line;
	char			*str;
	int				flag;

	str = input_by_line(fd);
	ret = output_by_line(mem_line, str);
	return (ret);
}
