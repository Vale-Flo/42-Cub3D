#include "cub3d.h"

// Using bitshifting to store the information of red green and blue

static int	get_rgb(char **split)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit_str(split[i]) || ft_atoi(split[i]) < 0
			|| ft_atoi(split[i]) > 255)
			return (free_split(split),
				ft_printf_error("Error\nRGB format not respected\n"), -1);
		i++;
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	return (free_split(split), r << 16 | g << 8 | b);
}

int	get_rgb_color(char *str, t_map *input)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ',');
	free(str);
	if (!split)
		perror_exit("Malloc failed", input);
	while (split[i])
		i++;
	if (i != 3)
		return (free_split(split),
			ft_printf_error("Error\nRGB format not respected\n"), -1);
	return (get_rgb(split));
}
