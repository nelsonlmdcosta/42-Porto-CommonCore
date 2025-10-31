/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:28:07 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/31 16:43:17 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnchar(char c, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += write(1, &c, 1);
	return (count);
}

int	ft_numberlength(t_ulong64 n, t_ulong64 base)
{
	int	len;

	len = 1;
	while (n >= (t_ulong64)base)
	{
		n /= base;
		++len;
	}
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_puthex_rec(t_ulong64 n, int upper)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_rec(n / 16, upper);
	write(1, &base[n % 16], 1);
}
