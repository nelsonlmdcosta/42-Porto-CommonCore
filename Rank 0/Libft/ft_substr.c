/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:12:56 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/12 20:14:35 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	totalsize;
	size_t	endindex;
	char	*output;

	totalsize = (len + 1);
	endindex = start + totalsize;
	output = malloc(sizeof(char) * totalsize);
	while (start < endindex)
	{
		*output = s[start];
		++start;
		++output;
	}
	*output = '\0';
	return (output - totalsize);
}
