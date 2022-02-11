#include "error.h"

void	put_error_exit(char *msg)
{
	ft_putstr_fd("Error: cub3D: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_free();
	exit(0);
}

void	put_ext_error_exit(char *obj, char *msg)
{
	ft_putstr_fd("Error: cub3D: ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_free();
	exit(0);
}
