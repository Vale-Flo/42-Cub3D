#include "cub3d.h"

void	init_input(t_map *input)
{
	int	i;

	i = 0;
	input->map = NULL;
	while (i < 4)
	{
		input->textures[i] = NULL;
		i++;
	}
	input->colors[0] = -1;
	input->colors[1] = -1;
}

void	load_textures(t_data *data, char **textures)
{
	int	i;

	i = 0;
	data->text_init = 0;
	while (i < 4)
	{
		data->textures[i].img = mlx_xpm_file_to_image(data->mlx,
				textures[i], &data->textures[i].bpp,
				&data->textures[i].line_length);
		if (data->textures[i].img == NULL)
		{
			ft_printf_error("Error\nFailed to load texture %s\n", textures[i]);
			ft_free_all(data);
			exit(1);
		}
		data->text_init++;
		data->textures[i].addr = mlx_get_data_addr(data->textures[i].img,
				&data->textures[i].bpp, &data->textures[i].line_length,
				&data->textures[i].endian);
		i++;
	}
}

// N and S are reversed as the y axis grows down in the window
// plane = a vector othogonal to vdir scaled by FOV
// In 2D, a vector perpendicular to (x, y) is (-y, x).

void	init_player(t_data *data, t_map *input)
{
	data->player.pos.x = input->player_x + 0.5;
	data->player.pos.y = input->player_y + 0.5;
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.1;
	if (input->player_o == 'E')
		data->player.dir = 0;
	else if (input->player_o == 'S')
		data->player.dir = M_PI_2;
	else if (input->player_o == 'W')
		data->player.dir = M_PI;
	else if (input->player_o == 'N')
		data->player.dir = 3 * M_PI_2;
	data->player.vdir.x = cos(data->player.dir);
	data->player.vdir.y = sin(data->player.dir);
	data->player.plane.x = -data->player.vdir.y * M_PI / 3;
	data->player.plane.y = data->player.vdir.x * M_PI / 3;
}

void	init_data(t_data *data, t_map *input)
{
	data->img_init = 0;
	data->i_map = input;
	data->mlx = mlx_init();
	data->win = NULL;
	if (data->mlx == NULL)
	{
		ft_printf_error("Error\nFailed to initialize mlx\n");
		free_input(data->i_map);
		exit(1);
	}
	load_textures(data, input->textures);
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "cub3D");
	data->img.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img_init = 1;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	data->floor_color = input->colors[0];
	data->ceiling_color = input->colors[1];
	data->map = input->map;
	init_player(data, input);
}
