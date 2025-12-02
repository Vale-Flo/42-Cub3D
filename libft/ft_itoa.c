#include "libft.h"

static int	nb_len(int n)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (n <= 0)
	{
		nb = -n;
		i++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	nb;

	i = nb_len(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	str[i--] = '\0';
	while (i >= (n < 0))
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

