/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:23:30 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:23:31 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	alloc_error(int size)
{
	ft_putstr_fd("ft_malloc: cannot allocate ", 2);
	ft_putnbr_fd(size, 2);
	ft_putstr_fd("bytes", 2);
	ft_free();
	exit(2);
}

void	add(void *ptr)
{
	void		**new;
	size_t		i;

	new = malloc(sizeof(void *) * (g_heap.count + 1));
	if (!new)
		alloc_error(sizeof(void *) * (g_heap.count + 1));
	i = 0;
	while (i < g_heap.count)
	{
		new[i] = g_heap.ptrs[i];
		i++;
	}
	new[g_heap.count] = ptr;
	g_heap.count++;
	if (g_heap.ptrs)
		free(g_heap.ptrs);
	g_heap.ptrs = new;
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!g_heap.count)
	{
		g_heap.count = 0;
		g_heap.ptrs = NULL;
	}
	ptr = malloc(size);
	if (!ptr)
		alloc_error(size);
	add(ptr);
	return (ptr);
}

void	ft_free(void)
{
	size_t	i;

	i = 0;
	while (i < g_heap.count)
		free(g_heap.ptrs[i++]);
	free(g_heap.ptrs);
}
