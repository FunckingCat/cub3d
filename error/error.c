/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:12:09 by tyamcha           #+#    #+#             */
/*   Updated: 2022/03/03 17:12:10 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
