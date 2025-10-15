/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:09:33 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/12 19:47:39 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
 * Finds the last occurence of a character in a string and returns that pointer.
 *
 * If not found returns nullptr
 * https://cplusplus.com/reference/cstring/strrchr/
 */
const char	*ft_strrchr(const char *str, int character)
{
	const char	*lastknownoccurence;

	lastknownoccurence = NULL;
	while (*str)
	{
		if (*str == character)
			lastknownoccurence = str;
		++str;
	}
	return (lastknownoccurence);
}
