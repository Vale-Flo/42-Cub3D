#include "cub3d.h"

void	perror_exit(const char *msg, t_map *input)
{
	perror(msg);
	free_input(input);
	exit(EXIT_FAILURE);
}

void	msg_error(char *s)
{
	ft_printf_error("%s\n", s);
	exit(EXIT_FAILURE);
}
