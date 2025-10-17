/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:09:33 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 16:59:06 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Finds the first character in a string and returns that pointer.
 *	Can technically find the null terminator char too so that's addded as a
 *		special case
 *
 * 	https://cplusplus.com/reference/cstring/strchr/
 */
const char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
			return (str);
		++str;
	}
	if (*str == (char)character)
		return (str);
	return (NULL);
}
