/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/18 19:44:37 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *  On Windows with MinGW, int and long are both 32-bit, unlike on most
 *  	platforms where long is 64-bit.
 *  To safely handle edge cases like INT_MIN, we convert the number to
 *  	unsigned long before processing, ensuring there is enough range
 *  	to represent the absolute value without overflow.
 */

/*
 *	Counts Digits In A Number, Always Expects Positive Numbers And
 *		Handles THe Special 0 case
 */
static int	count_digits(unsigned long number)
{
	int	counter;

	if (number == 0)
		return (1);
	counter = 0;
	while (number > 0)
	{
		number /= 10;
		++counter;
	}
	return (counter);
}

/*
 * 	Calculates the total buffer size required to be able to write into
 * 		Takes into consideration negatives if they exist, 0 and \0
 */
static int	calculate_buffer_size(long number)
{
	int				sign;
	unsigned long	unsignedvalue;

	unsignedvalue = (unsigned long)number;
	sign = 0;
	if (number < 0)
	{
		sign = 1;
		unsignedvalue = (unsigned long)(-number);
	}
	return (sign + count_digits(unsignedvalue) + 1);
}

/*
 * 	Converts an int to a string, dynamically allocating a string
 * 		at runtime with the exact length
 */
char	*ft_itoa(int i)
{
	unsigned long	positivedigits;
	size_t			length;
	char			*output;

	positivedigits = i;
	length = calculate_buffer_size(i);
	output = malloc(sizeof(char) * length);
	if (!output)
		return (NULL);
	if (i < 0)
	{
		output[0] = '-';
		positivedigits = (unsigned long)(-i);
	}
	output[--length] = '\0';
	if (positivedigits == 0)
		output[0] = '0';
	while (positivedigits)
	{
		output[--length] = (positivedigits % 10) + '0';
		positivedigits /= 10;
	}
	return (output);
}
