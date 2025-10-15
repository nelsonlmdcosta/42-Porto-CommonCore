/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:09:33 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 21:17:59 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
 * Finds the first character in a string and returns that pointer.
 *
 * If not found returns nullptr
 * https://cplusplus.com/reference/cstring/strchr/
 */
const char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
			return (str);
		++str;
	}
	return (NULL);
}
