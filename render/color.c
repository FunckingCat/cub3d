# include "./render.h"

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
	return (1 << 24 | ft_atoi(arr[0]) << 16 | ft_atoi(arr[1]) << 8 | ft_atoi(arr[2]));
}