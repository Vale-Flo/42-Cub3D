#include "cub3d.h"

void	free_input(t_map *input)
{
	int	i;

	i = 0;
	if (input->map)
		free_split(input->map);
	while (i < 4)
	{
		if (input->textures[i])
			free(input->textures[i]);
		i++;
	}
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->text_init)
	{
		if (data->textures[i].img)
			mlx_destroy_image(data->mlx, data->textures[i].img);
		i++;
	}
	if (data->img_init)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->i_map)
		free_input(data->i_map);
}

int	close_window(t_data *data)
{
	ft_free_all(data);
	exit(0);
}
