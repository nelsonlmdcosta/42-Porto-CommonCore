/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/10 20:20:25 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	*ft_memset(void *s, int c, size_t n);

/*
 * Creates a buffer for 20 digits for the biggest possible digit of 20 characters
 * 		on 64 bit systems
 */
char	*ft_itoa(int i)
{
	long	valuetoconvert;
	char	*output;
	char	*temp;

	valuetoconvert = 0;
	output = malloc(sizeof (char) * 20);
	ft_memset(output, 0, 20);
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
	*temp = '\0';
	return (output);
}
