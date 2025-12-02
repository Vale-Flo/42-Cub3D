#include "cub3d.h"

bool	is_direction(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	else
		return (false);
}

t_dir	get_direction(char c)
{
	if (c == 'N')
		return (NORTH);
	else if (c == 'E')
		return (EAST);
	else if (c == 'S')
		return (SOUTH);
	else
		return (WEST);
}

char	get_id(char c)
{
	if (c == 'N')
		return ('O');
	else if (c == 'E')
		return ('A');
	else if (c == 'S')
		return ('O');
	else
		return ('E');
}

int	skip_white_spaces(const char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\t' || line[i] == ' ' || line[i] == '\n')
		i++;
	return (i);
}

int	find_end_word(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\n')
		i++;
	return (i);
}
