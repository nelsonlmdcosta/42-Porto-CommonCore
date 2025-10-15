/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:11:12 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/12 20:02:53 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	*ft_memset(void *s, int c, size_t n);

/*
 *	Allocates and initializes a contiguous piece of memory
 */
void	*ft_calloc(size_t num, size_t size)
{
	void			*allocatedmemory;
	unsigned int	totaltoallocate;

	totaltoallocate = num * size;
	allocatedmemory = malloc(totaltoallocate);
	if (!allocatedmemory)
		return (NULL);
	ft_memset(allocatedmemory, 0, totaltoallocate);
	return (allocatedmemory);
}
