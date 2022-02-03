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
		fd = open(av [1], O_RDONLY);
	str = get_next_line(fd);
	printf("(1)%s", str);
	free(str);
	str = get_next_line(fd);
	printf("(2)%s", str);
	free(str);
	str = get_next_line(fd);
	printf("(3)%s", str);
	i = 0;
	while (str)
	{
		str = get_next_line(fd);
		printf("[%d]%s", i, str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
