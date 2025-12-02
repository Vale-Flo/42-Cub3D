#include "cub3d.h"

static void	malloc_and_copy_map(t_map *input, int size, t_list *list)
{
	int		i;
	t_list	*current;

	i = 0;
	current = list;
	input->map = malloc(sizeof(char *) * (size + 1));
	if (!input->map)
		perror_exit("Malloc failed", input);
	while (i < size)
	{
		input->map[i] = ft_strdup(current->content);
		if (!input->map[i])
			perror_exit("Malloc failed", input);
		i++;
		current = current->next;
	}
	input->map[size] = NULL;
	ft_lstclear(&list, free);
}

static bool	is_blank_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

static void	get_map(int fd, t_map *input)
{
	char	*line;
	t_list	*list;
	int		size;

	size = 0;
	list = NULL;
	line = get_next_line(fd);
	while (line && is_blank_str(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (is_blank_str(line))
			break ;
		if (!list)
			list = ft_lstnew(line);
		else
			ft_lstadd_back(&list, ft_lstnew(line));
		size++;
		line = get_next_line(fd);
	}
	free(line);
	malloc_and_copy_map(input, size, list);
}

bool	parse_map(int fd, t_map *input)
{
	char	*line;

	get_map(fd, input);
	if (!input->map)
		return (ft_printf_error("Error\nNo map was found\n"), false);
	line = get_next_line(fd);
	while (line && is_blank_str(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		return (free(line),
			ft_printf_error("Error\nFile does not end with map\n"), false);
	if (!check_invalid_char(input->map) || !check_player(input)
		|| !check_walls(input->map))
		return (false);
	return (true);
}
