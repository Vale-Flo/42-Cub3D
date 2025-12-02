#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;

	if ((!dest && !src) || !size)
		return (dest);
	if (dest > src)
	{
		d = dest + size - 1;
		s = src + size - 1;
		while (size--)
			*(d--) = *(s--);
	}
	else
	{
		d = dest;
		s = src;
		while (size--)
			*(d++) = *(s++);
	}
	return (dest);
}
