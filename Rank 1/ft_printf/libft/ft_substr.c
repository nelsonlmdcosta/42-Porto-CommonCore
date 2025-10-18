/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:12:56 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 17:42:10 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	string_length;
	size_t	substring_length;
	char	*output;
	size_t	i;

	if (!s)
		return (NULL);
	string_length = ft_strlen(s);
	if (start >= string_length)
		return (ft_strdup(""));
	substring_length = len;
	if (len > string_length - start)
		substring_length = string_length - start;
	output = malloc(substring_length + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (i < substring_length)
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
