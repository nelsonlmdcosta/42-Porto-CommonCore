/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:24:29 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/31 16:19:14 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	prepare_hex_format(t_format_info *f, unsigned int n)
{
	t_ulong64	num;

	num = n;
	if (n != 0 || !f->has_precision || f->precision != 0)
		f->nlen = ft_numberlength(num, 16);
	if (f->precision > f->nlen)
		f->prec = f->precision - f->nlen;
	if ((f->flags & FLAG_HASH) && n != 0)
		f->prefix = 2;
	if (f->width > f->nlen + f->prec + f->prefix)
		f->wdth = f->width - f->nlen - f->prec - f->prefix;
}

static int	print_hex_body(t_format_info *f, t_ulong64 num, int upper)
{
	int	count;

	count = 0;
	if (!(f->flags & FLAG_MINUS) && (!(f->flags & FLAG_ZERO)
			|| f->has_precision))
		count += ft_putnchar(' ', f->wdth);
	if (f->prefix)
	{
		if (upper)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}
	if (!(f->flags & FLAG_MINUS) && (f->flags & FLAG_ZERO)
		&& !f->has_precision)
		count += ft_putnchar('0', f->wdth);
	count += ft_putnchar('0', f->prec);
	if (f->nlen)
	{
		ft_puthex_rec(num, upper);
		count += f->nlen;
	}
	if (f->flags & FLAG_MINUS)
		count += ft_putnchar(' ', f->wdth);
	return (count);
}

int	ft_print_hex(t_format_info *f, unsigned int n, int upper)
{
	t_ulong64	num;
	int			count;

	num = n;
	count = 0;
	prepare_hex_format(f, n);
	count += print_hex_body(f, num, upper);
	return (count);
}

static void	prepare_ptr_format(t_format_info *f, unsigned long long num)
{
	f->nlen = 0;
	if (num != 0 || !f->has_precision || f->precision != 0)
		f->nlen = ft_numberlength(num, 16);
	f->prec = 0;
	if (f->precision > f->nlen)
		f->prec = f->precision - f->nlen;
	f->wdth = 0;
	if (f->width > f->nlen + f->prec + 2)
		f->wdth = f->width - f->nlen - f->prec - 2;
}

int	ft_print_ptr(t_format_info *f, void *ptr)
{
	unsigned long long	num;
	int					count;

	num = (unsigned long long)ptr;
	count = 0;
	prepare_ptr_format(f, num);
	if (!(f->flags & FLAG_MINUS))
		count += ft_putnchar(' ', f->wdth);
	count += write(1, "0x", 2);
	count += ft_putnchar('0', f->prec);
	if (f->nlen)
	{
		ft_puthex_rec(num, 0);
		count += f->nlen;
	}
	if (f->flags & FLAG_MINUS)
		count += ft_putnchar(' ', f->wdth);
	return (count);
}
