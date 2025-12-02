#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*temp;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	temp = ft_strjoin((const char *) s1, (const char *) s2);
	free(s1);
	return (temp);
}
