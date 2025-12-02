#include "cub3d.h"

void	display_input(t_map input)
{
	int	i;

	i = 0;
	ft_printf("INPUT STRUCTURE AFTER PARSING\n");
	ft_printf("--TEXTURES\n");
	ft_printf("textures[NORTH] = %s\n", input.textures[NORTH]);
	ft_printf("textures[EAST] = %s\n", input.textures[EAST]);
	ft_printf("textures[SOUTH] = %s\n", input.textures[SOUTH]);
	ft_printf("textures[WEST] = %s\n", input.textures[WEST]);
	ft_printf("\n--COLORS\n");
	ft_printf("colors[FLOOR] = %i\n", input.colors[0]);
	ft_printf("colors[CEILING] = %i\n", input.colors[1]);
	ft_printf("\n--MAP\n");
	while (input.map[i])
	{
		ft_printf("|%s|\n", input.map[i]);
		i++;
	}
	ft_printf("\n--PLAYER INFO\n");
	ft_printf("player_x = %i\n", input.player_x);
	ft_printf("player_y = %i\n", input.player_y);
	ft_printf("player_o = %c\n", input.player_o);
}
