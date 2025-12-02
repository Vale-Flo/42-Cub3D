#include "libft.h"

static char	*g_largebuf;

void	gnl_clear(void)
{
	if (g_largebuf)
	{
		free(g_largebuf);
		g_largebuf = NULL;
	}
}

static char	*read_file(char **g_largebuf, int fd)
{
	char	*buf;
	int		count;

	count = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(*g_largebuf);
		return (NULL);
	}
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[count] = '\0';
		*g_largebuf = ft_strjoinfree(*g_largebuf, buf);
		if (ft_strchr(buf, '\n'))
			count = 0;
	}
	free(buf);
	return (*g_largebuf);
}

static char	*extract_line(char *g_largebuf)
{
	char	*line;
	int		i;

	i = 0;
	while (g_largebuf[i] && g_largebuf[i] != '\n')
		i++;
	if (g_largebuf[i] == '\n')
	{
		line = ft_substr(g_largebuf, 0, i);
		if (!line)
			free(g_largebuf);
		return (line);
	}
	line = ft_strdup(g_largebuf);
	if (!line)
		free(g_largebuf);
	return (line);
}

static char	*clean_buf(char *g_largebuf)
{
	char	*newbuf;
	size_t	i;

	i = 0;
	while (g_largebuf[i] && g_largebuf[i] != '\n')
		i++;
	if (g_largebuf[i] == '\n' && g_largebuf[i + 1])
	{
		newbuf = ft_strdup(g_largebuf + i + 1);
		free(g_largebuf);
		return (newbuf);
	}
	free(g_largebuf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!g_largebuf)
	{
		g_largebuf = ft_strdup("");
		if (!g_largebuf)
			return (NULL);
	}
	if (!read_file(&g_largebuf, fd) || !*g_largebuf)
	{
		free(g_largebuf);
		g_largebuf = NULL;
		return (NULL);
	}
	line = extract_line(g_largebuf);
	if (!line)
		return (free(g_largebuf), NULL);
	g_largebuf = clean_buf(g_largebuf);
	return (line);
}
