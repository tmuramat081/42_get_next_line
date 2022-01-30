#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char 	*get_next_line(int fd);
char	*input_by_line(int fd);
int		output_by_line(char **mem_line, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);

#endif