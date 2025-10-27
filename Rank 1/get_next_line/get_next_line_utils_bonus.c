/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:33:48 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/27 16:36:51 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		++counter;
	return (counter);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

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

int	has_newline(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		++s;
	}
	return (0);
}

/*
 * 	Let's Count To Either \0 or \n if we hit \n then we add one more just to
 * 		ensure It's taken into consideration into the buffer, as it needs to
 * 		be kept
 */
int	len_until_newline(const char *string)
{
	int	counter;

	counter = 0;
	while (*(string + counter) && *(string + counter) != '\n')
		++counter;
	if (*(string + counter) == '\n')
		++counter;
	return (counter);
}
