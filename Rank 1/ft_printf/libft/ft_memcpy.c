/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:08:13 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 22:37:09 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	Should only be used when the memory does not overlap
 * 	https://man7.org/linux/man-pages/man3/memcpy.3.html
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				counter;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	counter = 0;
	while (counter < n)
	{
		d[counter] = s[counter];
		++counter;
	}
	return (dest);
}
