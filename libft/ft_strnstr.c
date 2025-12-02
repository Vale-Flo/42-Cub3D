#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t len)
{
	size_t	i;

	if (!*tofind)
		return ((char *)src);
	while (*src && len > 0)
	{
		i = 0;
		if (*src == *tofind)
		{
			i++;
			while (*(src + i) && *(tofind + i)
				&& *(src + i) == *(tofind + i) && len - i > 0)
				i++;
			if (i == ft_strlen(tofind))
				return ((char *)src);
		}
		src++;
		len--;
	}
	return (0);
}

