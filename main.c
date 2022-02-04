#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>



int	main(int ac, char **av)
{
	int fd;
	char *str;
	int i;

	(void)ac;
	puts("-----TEST-----");
	if (ac == 1)
		fd = open("./test01.txt", O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	printf("[00]%s", str);
	i = 1;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		printf("[%02d]%s", i, str);
		i++;
	}
	close(fd);
	return (0);
}
