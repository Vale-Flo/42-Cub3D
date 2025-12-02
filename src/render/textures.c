#include "cub3d.h"

/*
On calcule les coordonees des textures pour le mur
1. On determine ou exactement le mur a ete touche (hit)
2. On calcule les cordonnees de la texture
*/
void	calculate_tex_coords(t_data *data)
{
	int	tex_width;
	int	tex_height;

	tex_width = 64;
	tex_height = 64;
	if (data->ray.side == 0)
	{
		data->draw.wall_x = data->player.pos.y + data->ray.perp_wall_dist
			* data->ray.dir.y;
		if (data->ray.step_x < 0)
			data->draw.tex_num = WEST;
		else
			data->draw.tex_num = EAST;
	}
	else
	{
		data->draw.wall_x = data->player.pos.x + data->ray.perp_wall_dist
			* data->ray.dir.x;
		if (data->ray.step_y < 0)
			data->draw.tex_num = NORTH;
		else
			data->draw.tex_num = SOUTH;
	}
	calculate_tex_position(data, tex_width, tex_height);
}

/*
On calcule la position exacte de la texture
*/
void	calculate_tex_position(t_data *data, int tex_width, int tex_height)
{
	data->draw.wall_x -= floor(data->draw.wall_x);
	data->draw.tex_x = (int)(data->draw.wall_x * tex_width);
	if (data->ray.side == 0)
	{
		if (data->ray.dir.x > 0)
			data->draw.tex_x = tex_width - data->draw.tex_x - 1;
	}
	else
	{
		if (data->ray.dir.y < 0)
			data->draw.tex_x = tex_width - data->draw.tex_x - 1;
	}
	data->draw.tex_step = 1.0 * tex_height / data->ray.line_height;
	data->draw.tex_pos = (data->draw.draw_start - WIN_H / 2
			+ data->ray.line_height / 2) * data->draw.tex_step;
}

/*
Draw the textured wall for the given x coordinate
*/
void	draw_textured_wall(t_data *data, int x)
{
	int		y;
	int		tex_y;
	int		color;
	t_img	*texture;

	texture = &data->textures[data->draw.tex_num];
	y = data->draw.draw_start;
	while (y <= data->draw.draw_end)
	{
		tex_y = (int)data->draw.tex_pos % 64;
		data->draw.tex_pos += data->draw.tex_step;
		color = *(unsigned int *)(texture->addr + (tex_y * texture->line_length
					+ data->draw.tex_x * (texture->bpp / 8)));
		ft_put_pixel(&data->img, (t_vector2){x, y}, color);
		y++;
	}
}
