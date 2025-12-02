#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map	input;
	t_data	data;

	if (ac != 2)
	{
		ft_printf_error("Error\nCorrect usage is : ./cub3d <map.cub>\n");
		return (0);
	}
	init_input(&input);
	if (!parsing(av[1], &input))
		return (free_input(&input), 0);
	init_data(&data, &input);
	draw_background(&data);
	mlx_hook(data.win, 2, 1L << 0, key_handler, &data);
	mlx_hook(data.win, 17, 1L << 0, close_window, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	free_input(&input);
	return (0);
}
