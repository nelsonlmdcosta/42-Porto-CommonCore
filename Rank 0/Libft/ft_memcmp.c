/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:10:22 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 21:21:58 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * https://cplusplus.com/reference/cstring/memcmp/
 */
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*as_str1;
	const unsigned char	*as_str2;

	as_str1 = (const unsigned char *)ptr1;
	as_str2 = (const unsigned char *)ptr2;
	while (num--)
	{
		if (*as_str1 != *as_str2)
			return (*as_str1 - *as_str2);
		++as_str1;
		++as_str2;
	}
	return (0);
}
