#include "cub3d.h"

/*
with dda we calculate the euclidean distance
to the next vertical or horizontal line
while we haven't hit a wall,
we advance on the grid by the shortest step
*/
void	perform_dda(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray;
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (is_wall(data->i_map->map[ray->map_y][ray->map_x]))
			data->ray.hit = 1;
	}
}

/*
1. we calculate the perpendicular distance to the wall
to avoid fisheye distortion
2. we calculate the height of the line to draw
3. we calculate the start and end of the line to draw
and if the line is out of bounds we adjust it
*/

void	calculate_wall(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.map_x - data->player.pos.x + (1
					- data->ray.step_x) / 2) / data->ray.dir.x;
	else
		data->ray.perp_wall_dist = (data->ray.map_y - data->player.pos.y + (1
					- data->ray.step_y) / 2) / data->ray.dir.y;
	data->ray.line_height = (int)(WIN_H / data->ray.perp_wall_dist);
	data->draw.draw_start = -data->ray.line_height / 2 + WIN_H / 2;
	if (data->draw.draw_start < 0)
		data->draw.draw_start = 0;
	data->draw.draw_end = data->ray.line_height / 2 + WIN_H / 2;
	if (data->draw.draw_end >= WIN_H)
		data->draw.draw_end = WIN_H - 1;
	calculate_tex_coords(data);
}

/*
for each pixel x of the window, we calculate the ray
and draw a vertical line proportional to the distance to the wall
*/
void	render_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		calculate_ray(data, x);
		perform_dda(data);
		calculate_wall(data);
		draw_textured_wall(data, x);
		x++;
	}
}
