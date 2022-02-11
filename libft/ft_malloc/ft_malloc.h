/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:24:54 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:24:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_heap
{
	size_t	count;
	void	**ptrs;
	void	*ptr;
}	t_heap;

t_heap	g_heap;

void	*ft_malloc(size_t size);
void	ft_free(void);

#endif