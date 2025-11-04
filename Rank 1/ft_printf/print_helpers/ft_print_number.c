/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:23:53 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/11/01 10:46:10 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * 	Helper To Print Out THe Unsigned Numbers
 */
static void	putnbr_rec_unsigned(t_ulong64 n)
{
	char	character_to_print;

	if (n >= 10)
		putnbr_rec_unsigned(n / 10);
	character_to_print = (n % 10) + '0';
	write(1, &character_to_print, 1);
}

/*
 * To Compress this into a workable format for nomrinette and all that bs here
 * is a rundown of what's in here
 *
 * holy fuck dude, had to do the same check twice because of norminette and
 * to keep everything together, honestly norminette really needs work on
 * expanding the numbers by a fucking smidge ... >_> just to avoid the cost
 * of the extra bracket going over the line limiiiiiiiiiit :))))))
 *
 * If you see this 42 schools peeps, fucking change norminette to be less
 * annoying please this is ridiculous.
 */
static int	prtwflg(t_format_info *f, t_long64 n)
{
	int	count;

	count = 0;
	if (!(f->flags & FLAG_MINUS) && (!(f->flags & FLAG_ZERO)
			|| f->has_precision))
		count += ft_putnchar(' ', f->wdth);
	if (n < 0)
		count += ft_putnchar('-', 1);
	if (n < 0)
		n = -n;
	else if (f->flags & FLAG_PLUS)
		count += ft_putnchar('+', 1);
	else if (f->flags & FLAG_SPACE)
		count += ft_putnchar(' ', 1);
	if (!(f->flags & FLAG_MINUS) && (f->flags & FLAG_ZERO) && !f->has_precision)
		count += ft_putnchar('0', f->wdth);
	count += ft_putnchar('0', f->prec);
	if (f->nlen)
	{
		putnbr_rec_unsigned(n);
		count += f->nlen;
	}
	if (f->flags & FLAG_MINUS)
		count += ft_putnchar(' ', f->wdth);
	return (count);
}

/*
 * This was a bitch to compress down to what Norminette accepts >_>
 * So It's a Wee bit Unreadable imho
 *
 * 	This one can basically take all the flags, I didn't expect that
 * 		and well here e are, probably the hardest one of the bunch
 * 		to get right. So if you did it after the strings and got
 * 		cocky like i did this one punched you down a notch :'D
 *
 * 	All requested flags need to work on it except for # for hex
 *		0 -
 * 0 - + " " . all work! oh happy days :)
 */
int	ft_print_number(t_format_info *f, int n)
{
	t_long64	num;

	num = n;
	if (num != 0 || !f->has_precision || f->precision != 0)
	{
		if (num < 0)
			f->nlen = ft_numberlength(-num, 10);
		else
			f->nlen = ft_numberlength(num, 10);
	}
	if (f->precision > f->nlen)
		f->prec = f->precision - f->nlen;
	if (f->width > f->nlen + f->prec + (n < 0))
		f->wdth = f->width - f->nlen - f->prec - (n < 0);
	return (prtwflg(f, num));
}

static int	prtwflg_unsigned(t_format_info *f, t_ulong64 n)
{
	int	count;

	count = 0;
	if (!(f->flags & FLAG_MINUS)
		&& (!(f->flags & FLAG_ZERO) || f->has_precision))
		count += ft_putnchar(' ', f->wdth);
	if (!(f->flags & FLAG_MINUS)
		&& (f->flags & FLAG_ZERO) && !f->has_precision)
		count += ft_putnchar('0', f->wdth);
	count += ft_putnchar('0', f->prec);
	if (f->nlen)
	{
		putnbr_rec_unsigned(n);
		count += f->nlen;
	}
	if (f->flags & FLAG_MINUS)
		count += ft_putnchar(' ', f->wdth);
	return (count);
}

/*
 *
 * 0 - .
 */
int	ft_print_unsigned(t_format_info *f, unsigned int n)
{
	if (n != 0 || !f->has_precision || f->precision != 0)
		f->nlen = ft_numberlength(n, 10);
	if (f->precision > f->nlen)
		f->prec = f->precision - f->nlen;
	if (f->width > f->nlen + f->prec)
		f->wdth = f->width - f->nlen - f->prec;
	return (prtwflg_unsigned(f, n));
}
