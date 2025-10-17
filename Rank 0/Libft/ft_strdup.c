/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:11:30 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 16:59:33 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Allocates a string and duplicates it's data into the new buffer.
 */
char	*ft_strdup(char *src)
{
	size_t	length;
	size_t	counter;
	char	*buffer;

	counter = 0;
	length = ft_strlen(src) + 1;
	buffer = malloc(sizeof(char) * length);
	if (!buffer)
	{
		return (NULL);
	}
	while (counter < length)
	{
		*(buffer + counter) = *(src + counter);
		++counter;
	}
	return (buffer);
}
