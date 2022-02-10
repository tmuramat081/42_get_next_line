#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd[4];
	char *str1;
	char *str2;
	char *str3;

	puts("-----TEST-----");
	fd[1] = open("./test01.txt", O_RDONLY);
	fd[2] = open("./test02.txt", O_RDONLY);
	fd[3] = open("./test03.txt", O_RDONLY);

	str1 = get_next_line(fd[1]);
	printf("%s", str1);
	str2 = get_next_line(fd[2]);
	printf("%s", str2);
	str3 = get_next_line(fd[3]);
	printf("%s", str3);
	free(str1);
	free(str2);
	free(str3);
	int i = 1;
	while (i < 50)
	{
		str1 = get_next_line(fd[1]);
		printf("[01]%s", str1);
		str2 = get_next_line(fd[2]);
		printf("[02]%s", str2);
		str3 = get_next_line(fd[3]);
		printf("[03]%s", str3);
		free(str1);
		free(str2);
		free(str3);
		i++;
	}
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (0);
}
