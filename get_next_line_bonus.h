/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:30 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/07 17:00:26 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define RETURN 1
# define CONTINUE 0
# define ERROR -1
# define END_OF_FILE -2

typedef struct s_buff {
	char	*mem;
	char	*ptr_nl;
	int		sts;
}	t_buff;

char	*get_next_line(int fd);
void	read_buffer(int fd, char *buff, t_buff	*input);
char	*output_one_line(t_buff *input);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *c);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, char c);

#endif