#include "cub3d.h"

/* a simple function to put a pixel to the screen by its x and y coordinates */
void	ft_put_pixel(t_img *img, t_vector2 v, int color)
{
	char	*pxl;

	if (v.x >= 0 && v.x < WIN_W && v.y >= 0 && v.y < WIN_H)
	{
		pxl = img->addr + ((int)v.y * img->line_length + (int)v.x * (img->bpp
					/ 8));
		*(unsigned int *)pxl = color;
	}
}

void	draw_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			if (i < WIN_H / 2)
				ft_put_pixel(&data->img, (t_vector2){j, i},
					data->ceiling_color);
			else
				ft_put_pixel(&data->img, (t_vector2){j, i}, data->floor_color);
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_background(data);
	render_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
