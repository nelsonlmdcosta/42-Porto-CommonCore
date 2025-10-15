/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:35 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/12 20:33:13 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

static int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
 * Trims a strings start and end, anything between is untouched
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	startindex;
	size_t	endindex;
	char	*output;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	startindex = 0;
	while (s1[startindex] && in_set(s1[startindex], set))
		startindex++;
	endindex = ft_strlen(s1);
	while (endindex > startindex && in_set(s1[endindex - 1], set))
		endindex--;
	output = (char *)malloc(endindex - startindex + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (startindex < endindex)
		output[i++] = s1[startindex++];
	output[i] = '\0';
	return (output);
}
