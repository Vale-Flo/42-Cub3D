#include "libft.h"

static int	convert_arg(char c, va_list args, const char *s1, const char *s2)
{
	void	*ptr;

	if (c == 'c')
		return (ft_putchar_len((unsigned char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr_len("(nil)"));
		ft_putstr_len("0x");
		return (ft_putnbr_hex_len((unsigned long)ptr, (char *)s1) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u_len(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_hex_len(va_arg(args, unsigned int), (char *)s1));
	else if (c == 'X')
		return (ft_putnbr_hex_len(va_arg(args, unsigned int), (char *)s2));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	is_handled(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && is_handled(format[i + 1]))
		{
			len += convert_arg(format[i + 1], args,
					"0123456789abcdef", "0123456789ABCDEF");
			i += 2;
		}
		else
		{
			len += ft_putchar_len(format[i]);
			i++;
		}
	}
	return (len);
}
