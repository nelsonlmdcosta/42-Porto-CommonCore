/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:10:08 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 21:22:00 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Find a string within a given block of memory
 *
 * Just goes through the blocks of a byte till it finds the character in the
 * 		extended ascii family
 *
 * https://cplusplus.com/reference/cstring/memchr/
 */
const void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*str;
	unsigned char		charactertofind;

	str = (const unsigned char *)ptr;
	charactertofind = (unsigned char)value;
	while (num--)
	{
		if (*str == charactertofind)
			return ((void *)str);
		++str;
	}
	return (NULL);
}
