#include "cub3d.h"

void	handle_ad(int keysym, t_data *data)
{
	t_player	*p;
	double		new_x;
	double		new_y;

	p = &data->player;
	new_x = p->pos.x + p->vdir.y * p->move_speed;
	new_y = p->pos.y - p->vdir.x * p->move_speed;
	if (keysym == KEY_A && data->map[(int)new_y][(int)new_x] != '1')
	{
		p->pos.x = new_x;
		p->pos.y = new_y;
	}
	new_x = p->pos.x - p->vdir.y * p->move_speed;
	new_y = p->pos.y + p->vdir.x * p->move_speed;
	if (keysym == KEY_D && data->map[(int)new_y][(int)new_x] != '1')
	{
		p->pos.x = new_x;
		p->pos.y = new_y;
	}
}

void	handle_ws(int keysym, t_data *data)
{
	t_player	*p;
	double		new_x;
	double		new_y;

	p = &data->player;
	new_x = p->pos.x + p->vdir.x * p->move_speed;
	new_y = p->pos.y + p->vdir.y * p->move_speed;
	if (keysym == KEY_W && data->map[(int)new_y][(int)new_x] != '1')
	{
		p->pos.x = new_x;
		p->pos.y = new_y;
	}
	new_x = p->pos.x - p->vdir.x * p->move_speed;
	new_y = p->pos.y - p->vdir.y * p->move_speed;
	if (keysym == KEY_S && data->map[(int)new_y][(int)new_x] != '1')
	{
		p->pos.x = new_x;
		p->pos.y = new_y;
	}
}

// 1.Rotate direction vector
// 2.Rotate camera plane
// 3.Update the direction angle

void	rotate(t_data *data, int keysym)
{
	double	old_dir_x;
	double	rotate_speed;
	double	old_plane_x;

	old_dir_x = data->player.vdir.x;
	if (keysym == KEY_LEFT)
		rotate_speed = -data->player.rot_speed;
	else
		rotate_speed = data->player.rot_speed;
	data->player.vdir.x = data->player.vdir.x * cos(rotate_speed)
		- data->player.vdir.y * sin(rotate_speed);
	data->player.vdir.y = old_dir_x * sin(rotate_speed)
		+ data->player.vdir.y * cos(rotate_speed);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(rotate_speed)
		- data->player.plane.y * sin(rotate_speed);
	data->player.plane.y = old_plane_x * sin(rotate_speed)
		+ data->player.plane.y * cos(rotate_speed);
	data->player.dir = normalize_angle(data->player.dir + rotate_speed);
}

// Function for events with the keyboard
int	key_handler(int keysym, t_data *data)
{
	if (keysym == KEY_ESC || keysym == KEY_Q)
		close_window(data);
	else if (keysym == KEY_W || keysym == KEY_S)
		handle_ws(keysym, data);
	else if (keysym == KEY_A || keysym == KEY_D)
		handle_ad(keysym, data);
	else if (keysym == KEY_RIGHT || keysym == KEY_LEFT)
		rotate(data, keysym);
	return (0);
}
