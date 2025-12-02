#include "libft.h"

int	ft_putstr_len(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!s)
		return (ft_putstr_len("(null)"));
	while (s[i])
	{
		len += ft_putchar_len(s[i]);
		i++;
	}
	return (len);
}

int	ft_putchar_len(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_len(int n)
{
	unsigned int	nb;
	char			c;
	int				len;

	len = 0;
	if (n < 0)
	{
		nb = -n;
		len += write(1, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
		len += ft_putnbr_len(nb / 10);
	c = nb % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_putnbr_u_len(unsigned int n)
{
	char			c;
	int				len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_len(n / 10);
	c = n % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_putnbr_hex_len(unsigned long long nb, char *base)
{
	int				len;

	len = 0;
	if (nb > 15)
		len += ft_putnbr_hex_len(nb / 16, base);
	len += ft_putchar_len(base[nb % 16]);
	return (len);
}
