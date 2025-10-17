/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:10:42 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 17:26:56 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Just fancier strstr, finds a string inside another, up to a specific n
 *
 * Returns big if little is null, otherwise tries to find a substring.
 *		Otherwise returns NULL as it found nothing
 *
 * https://man.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	bigcounter;
	size_t	littlecounter;

	if (little[0] == '\0')
		return ((char *)big);
	bigcounter = 0;
	while (big[bigcounter] && bigcounter < len)
	{
		littlecounter = 0;
		while (little[littlecounter] && bigcounter + littlecounter < len
			&& big[bigcounter + littlecounter] == little[littlecounter])
			littlecounter++;
		if (little[littlecounter] == '\0')
			return ((char *)&big[bigcounter]);
		++bigcounter;
	}
	return (NULL);
}
