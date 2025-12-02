#include "cub3d.h"

static bool	get_texture(char *line, t_map *input, int *info)
{
	int		i;
	int		len;
	t_dir	dir;
	char	id;

	dir = get_direction(line[0]);
	id = get_id(line[0]);
	if (input->textures[dir])
		return (ft_printf_error("Error\nTwo lines have id %c\n", line[0]),
			false);
	i = 1 + (line[1] == id);
	i += skip_white_spaces(line + i);
	if (!line[i])
		return (ft_printf_error("Error\nNo path found on line with id %c\n",
				line[0]), false);
	len = find_end_word(line + i);
	input->textures[dir] = ft_substr(line, i, len);
	if (!input->textures[dir])
		perror_exit("Malloc failed", input);
	i += len + skip_white_spaces(line + i + len);
	if (line[i])
		return (ft_printf_error("Error\nToo much info on line with id %c\n",
				line[0]), false);
	(*info)++;
	return (true);
}

static bool	get_color(char *line, t_map *input, int *info)
{
	int		i;
	int		len;
	bool	ceiling;

	ceiling = (line[0] == 'C');
	if (input->colors[ceiling] != -1)
		return (ft_printf_error("Error\nTwo lines have id %c\n", line[0]),
			false);
	i = 1 + skip_white_spaces(line + 1);
	if (!line[i])
		return (ft_printf_error("Error\nNo color found on line with id %c\n",
				line[0]), false);
	len = find_end_word(line + i);
	input->colors[ceiling] = get_rgb_color(ft_substr(line, i, len), input);
	if (input->colors[ceiling] == -1)
		return (false);
	i += len + skip_white_spaces(line + i + len);
	if (line[i])
		return (ft_printf_error("Error\nToo much info on line with id %c\n",
				line[0]), false);
	(*info)++;
	return (true);
}

static bool	unexpected_line(char c, int info)
{
	if (c != '1')
		ft_printf_error("Error\nNot-empty extra line detected\n");
	else if (info < 6)
		ft_printf_error("Error\nMissing texture and/or color\n");
	return (false);
}

static bool	get_text_col(char *line, t_map *input, int *info)
{
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
		return (get_texture(line, input, info));
	else if (line[0] == 'F' || line[0] == 'C')
		return (get_color(line, input, info));
	return (false);
}

bool	parse_textures_colors(int fd, t_map *input)
{
	char	*line;
	bool	go_on;
	int		info;
	int		i;

	info = 0;
	go_on = true;
	while (go_on && info < 6)
	{
		line = get_next_line(fd);
		if (!line)
		{
			go_on = false;
			break ;
		}
		i = skip_white_spaces(line);
		if (is_direction(line[i]) || line[i] == 'F' || line[i] == 'C')
			go_on = get_text_col(line + i, input, &info);
		else if (line[i])
			go_on = unexpected_line(line[i], info);
		free(line);
	}
	return (go_on);
}
