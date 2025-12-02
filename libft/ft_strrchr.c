#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == (char)c)
			count++;
		temp++;
	}
	while (*s)
	{
		if (*s == (char)c && ++i == count)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
