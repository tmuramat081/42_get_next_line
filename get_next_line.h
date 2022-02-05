#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

typedef struct s_line {
	char	*str;
	char	*ptr_nl;
} t_line;

char 	*get_next_line(int fd);
char	*read_buffer(int fd);
void	save_memory(char *buff, t_line	*memory);
char	*output_one_line(t_line *memory);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *c);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
void	*ft_memchr(void *buff, int ch, size_t n);
char	*ft_strchr(const char *s, char c);

#endif