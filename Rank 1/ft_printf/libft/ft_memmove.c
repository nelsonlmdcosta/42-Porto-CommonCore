/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:08:24 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 22:37:14 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	Unlike memcpy these can overlap technically
 * 	https://man7.org/linux/man-pages/man3/memmove.3.html
 *
 * 	Naive implementation would probably just write over the buffer, but you
 * 		actually need to be somewhat careful
 *
 * 	Start by ensuring it's not the same pointers or copying nothing. That
 * 		would be silly
 * 	Then we need to either copy forwards (no overlap)
 * 		or copy backwards (onn memory overlap) to avoid overwriting data
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
