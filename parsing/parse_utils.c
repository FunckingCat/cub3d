#include "./parsing.h"

int	split_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (i);
	while (arr[i])
		i++;
	return (i);
}

int	hex_to_int(char *str)
{
	int		res;
	char	c;
	char	v;

	res = 0;
	if (*str == '#')
		str++;
	if (!ft_strcmp("None", str))
		return (34343434);
	while ((c = *str++))
	{
		v = (c & 0xF) + (c >> 6) | ((c >> 3) & 0x8);
		res = (res << 4) | (int) v;
	}
	if (res == 0)
		printf("ALERT\n");
	return res;
}