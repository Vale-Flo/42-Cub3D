#include "cub3d.h"

int	is_wall(char c)
{
    return (c == '1');
}

/*
step_x = -1 if we go left, step_x = 1 if we go right
step_y = -1 if we go up, step_y = 1 if we go down
side_dist_x = distance to the next vertical line
side_dist_y = distance to the next horizontal line
*/
void	get_step_and_side_dist(t_data *data, int map_x, int map_y)
{
    if (data->ray.dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.pos.x - map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (map_x + 1.0 - data->player.pos.x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.pos.y - map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (map_y + 1.0 - data->player.pos.y)
			* data->ray.delta_dist_y;
	}
}

/*
We get all the ray data for pixel x,
    to be able to use the DDA algorithm
1. calculate position on camera plane (-1 to 1)
2. calculate ray direction (if 0,
    we choose a very small value to avoid division by 0)
3. player position on the grid (float to int conversion)
4. calculate delta_distances (distance between grid lines
based on ray direction)
5. initialize step and side_dist
(distance to the next vertical or horizontal line)
*/
void	calculate_ray(t_data *data, int x)
{
	data->ray.camera_x = 2 * x / (double)WIN_W - 1;
	data->ray.dir.x = cos(data->player.dir) + data->player.plane.x
		* data->ray.camera_x;
	data->ray.dir.y = sin(data->player.dir) + data->player.plane.y
		* data->ray.camera_x;
	if (data->ray.dir.x == 0)
		data->ray.dir.x = 1e-30;
	if (data->ray.dir.y == 0)
		data->ray.dir.y = 1e-30;
	data->ray.map_x = (int)data->player.pos.x;
	data->ray.map_y = (int)data->player.pos.y;
	data->ray.delta_dist_x = fabs(1 / data->ray.dir.x);
	data->ray.delta_dist_y = fabs(1 / data->ray.dir.y);
	get_step_and_side_dist(data, data->ray.map_x, data->ray.map_y);
}
