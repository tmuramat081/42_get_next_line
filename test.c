#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int main (int ac, char **av)
{
	int fd;
	int ret;
	int i;
	char buff[64];

	(void)ac;
	puts("-----TEST-----");
	if (ac == 1)
		fd = open("./test01.txt", O_RDONLY);
	else
		fd = open(av [1], O_RDONLY);
	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret= read(fd, buff, 32);
		buff[ret] = '\0';
		printf("%s\n", buff);
		printf("No.%d ret=%d\n", i, ret);
		i++;
	}
}