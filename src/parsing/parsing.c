#include "cub3d.h"

int	check_file(char *path)
{
	int		fd;
	char	*ext;

	ext = ft_strnstr(path, ".cub", ft_strlen(path));
	while (ext && *(ext + 4))
	{
		ext += 4;
		ext = ft_strnstr(ext, ".cub", ft_strlen(ext));
	}
	if (!ext)
	{
		ft_printf_error("Error\nMap should have .cub extension\n", path);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_printf_error("Error\nFailed to open \"%s\"\n", path);
	return (fd);
}

bool	parsing(char *path, t_map *input)
{
	int	fd;

	fd = check_file(path);
	if (fd < 0)
		return (false);
	if (!parse_textures_colors(fd, input) || !parse_map(fd, input))
		return (gnl_clear(), close(fd), false);
	close(fd);
	return (true);
}
