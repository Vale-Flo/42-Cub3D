#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
	{
		*p = c;
		p++;
	}
	return (s);
}

