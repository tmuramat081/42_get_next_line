#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int test(void)
{
	static int i;

	if (i > 10)
		return (i);
	i++;
	printf("%d\n", i);
	test();
	return (0);
}

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
	i = test();
	printf("%d\n", i);
}