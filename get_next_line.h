/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:30 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/09 21:03:10 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 256

# define RETURN 1
# define CONTINUE 0
# define ERROR -1
# define END -2

typedef struct s_minfo {
	char	*mem;
	char	*ptr_nl;
	int		sts;
}	t_minfo;

char	*get_next_line(int fd);
void	read_buffer(int fd, char *buff, t_minfo	*input);
char	*output_one_line(t_minfo *input);
char	*free_memory(t_minfo *input);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *s, char c);

#endif