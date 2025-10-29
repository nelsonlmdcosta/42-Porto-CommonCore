/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:28:07 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/28 07:54:10 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int len = 0;
	if (!s)
		return write(1, "(null)", 6);
	while (s[len]) len++;
		write(1, s, len);
	return len;
}

int	ft_putnchar(char c, int n)
{
	int count = 0;
	while (n-- > 0)
		count += write(1, &c, 1);
	return count;
}

int	ft_numberlength(ulong64 n, int base)
{
	int len = 1;
	while (n >= (unsigned)base)
	{
		n /= base; len++;
	}
	return len;
}