#include "cub3d.h"

bool	check_invalid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& !is_direction(map[i][j]))
				return (ft_printf_error("Error\nInvalid character on the map\n"),
					false);
			j++;
		}
		i++;
	}
	return (true);
}

static int	get_player_info(int i, int j, char c, t_map *input)
{
	input->player_x = j;
	input->player_y = i;
	input->player_o = c;
	return (1);
}

bool	check_player(t_map *input)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (input->map[i])
	{
		j = 0;
		while (input->map[i][j])
		{
			if (is_direction(input->map[i][j]) && count == 0)
				count = get_player_info(i, j, input->map[i][j], input);
			else if (is_direction(input->map[i][j]))
				return (ft_printf_error("Error\nThere is more than one player"),
					false);
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_printf_error("Error\nThere must be a player\n"), false);
	return (true);
}

/* HOW TO CHECK WHETHER THE MAP IS SURROUNDED BY WALLS
If there is a 0 or a dir on the map
 - it cannot be on the first line (i == 0) or the first column (j == 0)
 - it cannot be on the last line (!map[i + 1])
 	or the last column (!map[i][j + 1])
 - its position (j) cannot exceed the size of the previous or next line
 - there cannot be a space in an adjacent box
*/

bool	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || is_direction(map[i][j])) && (i == 0
					|| map[i + 1] == NULL || j == 0 || !map[i][j + 1]
					|| (int)ft_strlen(map[i + 1]) <= j
					|| (int)ft_strlen(map[i - 1]) <= j
					|| ((int)ft_strlen(map[i + 1]) > j && map[i + 1][j] == ' ')
					|| ((int)ft_strlen(map[i - 1]) > j && map[i - 1][j] == ' ')
					|| map[i][j + 1] == ' '
					|| map[i][j - 1] == ' '))
				return (ft_printf_error("Error\nMap not surrounded by walls\n"),
					false);
			j++;
		}
		i++;
	}
	return (true);
}
