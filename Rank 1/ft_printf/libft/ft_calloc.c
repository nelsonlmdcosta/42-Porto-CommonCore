/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:11:12 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 17:41:43 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

/*
 *	Allocates and initializes a contiguous piece of memory
 *
 *	42 expects an allocation when either parameters are 0, so we make it 1 byte
 *		as a minimum and return that. I don't like unnecesary allocations but
 *		rules are the rules
 *
 *	We know (num * size) might overflow, so if we divide the maximum
 *		value of size_t (SIZE_MAX), by size, then the number cannot be greater
 *		than num. If the result of the division is greater than one then you
 *		cannot allocate as it would be impossible for the malloc()
 */
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	total;

	if (num == 0 || size == 0)
		return (malloc(1));
	if (num > SIZE_MAX / size)
		return (NULL);
	total = num * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
