/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 16:49:00 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	Creates a buffer for 11 digits for the biggest possible digit on 64 bit
 * 		systems
 */
char	*ft_itoa(int i)
{
	long	valuetoconvert;
	char	*output;
	char	*temp;

	valuetoconvert = 0;
	output = malloc(sizeof (char) * 11);
	ft_memset(output, 0, 11);
	temp = output;
	if (i == 0)
	{
		*temp++ = '0';
	}
	if (i < 0)
	{
		*temp++ = '-';
		valuetoconvert = (long)i;
		valuetoconvert *= -1;
	}
	while (valuetoconvert > 0)
	{
		*temp++ = '0' + valuetoconvert % 10;
		valuetoconvert /= 10;
	}
	return (output);
}
