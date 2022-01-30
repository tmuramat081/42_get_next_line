#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	len_s1;
	unsigned int	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)s1, len_s1 + 1);
	ft_strlcat(dest, (char *)s2, len_s1 + len_s2 + 1);
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	tmp = (char *)s + start;
	i = 0;
	while (*tmp && i < len)
		ret[i++] = *tmp++;
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlen(const char *c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (c[i] != '\0')
	{
		cnt += 1;
		i++;
	}
	return (cnt);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int		d_len;
	unsigned int		s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize < d_len)
		return (s_len + dstsize);
	ft_strlcpy (dst + d_len, src, dstsize - d_len);
	return (d_len + s_len);
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
