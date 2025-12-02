#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)buf1;
	p2 = (const unsigned char *)buf2;
	if (count == 0)
		return (0);
	while (--count > 0 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
