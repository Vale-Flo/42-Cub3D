#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t length)
{
	while (length-- > 0)
	{
		if (*(unsigned char *)buf == (unsigned char)c)
			return ((void *)buf);
		buf++;
	}
	return (0);
}

