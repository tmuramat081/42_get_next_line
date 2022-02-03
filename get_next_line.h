#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define CONTINUE 2
# define RETURN 1
# define END_OF_FILE 0
# define ERROR -1

typedef struct s_line {
	char	*ret;
	char	*mem;
	int		sts;
}	t_line;

char 	*get_next_line(int fd);
t_line	input_by_line(int fd, char *buff);
char 	*output_by_line(t_line input);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *c);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);

#endif