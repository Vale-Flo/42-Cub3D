/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-harco <md-harco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:40:14 by mahautdharc       #+#    #+#             */
/*   Updated: 2025/05/02 11:58:26 by md-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_W 1280
# define WIN_H 720

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define KEY_Q 113

/*
map = string array with 1s, 0s and a char N, E,
	S or W that corresponds to the initial orientation of the player
textures[4] = {N; E; S; W} and each string is the path to the texture
colors[2] = {F; C} and each int is the color in RGB format converted to int
*/
typedef struct s_map
{
	char		**map;
	int			player_x;
	int			player_y;
	char		player_o;
	char		*textures[4];
	int			colors[2];
}				t_map;

// Represents a point in 2D (float)
typedef struct s_vector2
{
	float		x;
	float		y;
}				t_vector2;

/*
camera_x = x position on the camera plane (-1 to 1)
side_dist_x = distance to the next vertical line
side_dist_y = distance to the next horizontal line
delta_dist_x = distance inbetween vertical lines
delta_dist_y = distance inbetween horizontal lines
*/
typedef struct s_ray
{
	float		camera_x;
	t_vector2	dir;
	int			map_x;
	int			map_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
}				t_ray;

typedef struct s_player
{
	t_vector2	pos;
	double		dir;
	t_vector2	vdir;
	t_vector2	plane;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_draw
{
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		tex_pos;
	double		tex_step;
}				t_draw;

// bpp = bits_per_pixel
typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;

}				t_img;

// Main structure
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		*i_map;
	t_draw		draw;
	t_player	player;
	t_ray		ray;
	char		**map;
	int			map_width;
	int			map_height;
	t_img		textures[4];
	int			text_init;
	int			img_init;
	int			floor_color;
	int			ceiling_color;
}				t_data;

// RENDER
int				close_window(t_data *data);
int				key_handler(int keysym, t_data *data);
void			ft_put_pixel(t_img *img, t_vector2 v, int color);
void			draw_background(t_data *data);
void			msg_error(char *s);
int				render(t_data *data);

// RAYCAST
double			normalize_angle(double angle);
int				is_wall(char c);
void			render_rays(t_data *data);
void			calculate_wall(t_data *data);
void			calculate_tex_coords(t_data *data);
void			calculate_tex_position(t_data *data, int tex_width,
					int tex_height);
void			draw_textured_wall(t_data *data, int x);
void			calculate_ray(t_data *data, int x);
void			get_step_and_side_dist(t_data *data, int map_x, int map_y);
int				is_wall(char c);

// PARSING
typedef enum s_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_dir;

bool			parsing(char *path, t_map *input);
bool			parse_textures_colors(int fd, t_map *input);
int				skip_white_spaces(const char *line);
bool			is_direction(char c);
t_dir			get_direction(char c);
char			get_id(char c);
int				find_end_word(const char *line);
int				get_rgb_color(char *str, t_map *input);
bool			parse_map(int fd, t_map *input);
bool			check_walls(char **map);
bool			check_player(t_map *input);
bool			check_invalid_char(char **map);

// UTILS
void			free_input(t_map *input);
void			free_split(char **split);
void			perror_exit(const char *msg, t_map *input);
void			init_input(t_map *input);
void			init_data(t_data *data, t_map *input);
void			ft_free_all(t_data *data);
void			ft_free_all(t_data *data);
int				close_window(t_data *data);

// DEBUG FUNCTIONS
void			display_input(t_map input);

#endif
