/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:49:32 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/08 13:25:51 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen(src);
	p = (char *) malloc (sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, src, len + 1);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)s1, len_s1 + 1);
	ft_strlcpy(dest + len_s1, (char *)s2, len_s2 + 1);
	return (dest);
}

char	*ft_strchr(const char *s, char c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (1)
	{
		if (s1[i] == c)
			return (&s1[i]);
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *c)
{
	size_t	cnt;

	if (!c)
		return (0);
	cnt = 0;
	while (*c++ != '\0')
		cnt += 1;
	return (cnt);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	if (!n)
		return (ft_strlen(s));
	i = 0;
	while (i < n - 1 && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(s));
}
