#include "libft.h"

static int	count_elements(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		elementlen;
	int			i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (count_elements(s, c) + 1));
	if (!s || !split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				elementlen = ft_strlen(s);
			else
				elementlen = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, elementlen);
			s += elementlen;
		}
	}
	split[i] = NULL;
	return (split);
}

