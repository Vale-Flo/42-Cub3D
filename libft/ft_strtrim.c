#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trimlen(char const *s1, char const *set)
{
	int	totallen;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] && isset(s1[i], set))
		i++;
	while (s1[len] && isset(s1[len], set))
		len--;
	totallen = len - i + 1;
	return (totallen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		len;

	len = trimlen(s1, set);
	i = 0;
	while (s1[i] && isset(s1[i], set))
		i++;
	trim = ft_substr(s1, i, len);
	if (!trim)
		return (NULL);
	return (trim);
}

