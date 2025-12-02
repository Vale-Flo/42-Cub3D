#include "libft.h"

int	ft_putstr_len_err(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!s)
		return (ft_putstr_len_err("(null)"));
	while (s[i])
	{
		len += ft_putchar_len_err(s[i]);
		i++;
	}
	return (len);
}

int	ft_putchar_len_err(unsigned char c)
{
	return (write(2, &c, 1));
}

int	ft_putnbr_len_err(int n)
{
	unsigned int	nb;
	char			c;
	int				len;

	len = 0;
	if (n < 0)
	{
		nb = -n;
		len += write(2, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
		len += ft_putnbr_len_err(nb / 10);
	c = nb % 10 + '0';
	len += write(2, &c, 1);
	return (len);
}

int	ft_putnbr_u_len_err(unsigned int n)
{
	char			c;
	int				len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_len_err(n / 10);
	c = n % 10 + '0';
	len += write(2, &c, 1);
	return (len);
}

int	ft_putnbr_hex_len_err(unsigned long long nb, char *base)
{
	int				len;

	len = 0;
	if (nb > 15)
		len += ft_putnbr_hex_len_err(nb / 16, base);
	len += ft_putchar_len_err(base[nb % 16]);
	return (len);
}
