# include "./render.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	char_to_hex(char **arr)
{
	if (split_size(arr) != 3)
		put_error_exit(ERR_COL_FORMAT);
	if (!ft_isstrdigit(arr[0]) ||
		!ft_isstrdigit(arr[1]) ||
		!ft_isstrdigit(arr[2]))
		put_error_exit(ERR_COL_FORMAT);
	if (ft_atoi(arr[0]) > 255 ||
		ft_atoi(arr[1]) > 255 ||
		ft_atoi(arr[2]) > 255)
		put_error_exit(ERR_COL_FORMAT);
	return (create_trgb(1, ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2])));
}