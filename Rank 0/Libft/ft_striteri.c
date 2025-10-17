/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:14:23 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 17:02:51 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	counter;

	if (!s || !f)
		return ;
	counter = 0;
	while (*(s + counter) != '\0')
	{
		f(counter, s + counter);
		++counter;
	}
}
