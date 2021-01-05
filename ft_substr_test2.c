#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			str[i] = '\0';
			i++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (!(str = malloc(count * size)))
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*buffer_dst;
	char	*buffer_src;

	buffer_dst = (char*)dst;
	buffer_src = (char*)src;
	if (dst == src)
		return (dst);
	while (n--)
		*buffer_dst++ = *buffer_src++;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

int main()
{
    char *str = "01234";
    size_t size = 2;
    char *ret = ft_substr(str, 2, size);
    printf("%s", ret);
    return 0;
}
