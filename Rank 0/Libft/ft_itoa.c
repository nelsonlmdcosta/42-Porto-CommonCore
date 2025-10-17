/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 18:18:58 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long number)
{
	int	counter;

	counter = 0;
	while (number > 0)
	{
		number /= 10;
		++counter;
	}
	return (counter);
}

static int	calculate_buffer_size(long number)
{
	int	length;

	length = 0;
	if (number < 0)
		length = 1;
	return (length + count_digits(number) + 1);
}

/*
 * 	Creates a buffer for 11 digits for the biggest possible digit on 64 bit
 * 		systems
 */
char	*ft_itoa(int i)
{
	long	number;
	size_t	length;
	char	*output;

	number = i;
	length = calculate_buffer_size(number);
	output = malloc(length);
	if (!output)
		return (NULL);
	if (i < 0)
	{
		output[0] = '-';
		number *= -1;
	}
	output[length] = '\0';
	if (number == 0)
		output[0] = '0';
	while (number)
	{
		output[--length] = (number % 10) + '0';
		number /= 10;
	}
	return (output);
}
