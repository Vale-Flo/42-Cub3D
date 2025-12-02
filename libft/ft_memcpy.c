#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	if ((!dest && !src) || !size)
		return (dest);
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
