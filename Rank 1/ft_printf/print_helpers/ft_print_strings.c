/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:23:17 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/11/05 20:39:49 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * 	From my understanding char can only use the minus flag to add the requested
 * 		space at the beginning or the end, aka "justify" the text, we right
 * 		justify by default, so the padding is at the start, if the - flag is
 * 		present then we left justify, aka we place the character THEN place the
 * 		padding
 *
 * 		Only alignment (-) works on this type
 */
int	ft_print_char(t_format_info *format_info, char c)
{
	int	pad;
	int	count;

	pad = 0;
	if (format_info->width > 1)
		pad = format_info->width - 1;
	count = 0;
	if (!(format_info->flags & FLAG_MINUS))
		count += ft_putnchar(' ', pad);
	count += ft_putnchar(c, 1);
	if (format_info->flags & FLAG_MINUS)
		count += ft_putnchar(' ', pad);
	return (count);
}

/*
 * 	From my understanding string can only use the minus flag to add the requested
 * 		space at the beginning or the end, aka "justify" the text, we right
 * 		justify by default, so the padding is at the start, if the - flag is
 * 		present then we left justify, aka we place the character THEN place the
 * 		padding
 *
 * 		Only alignment (-) and precision (.) work on this type
 */
int	ft_print_str(t_format_info *f, char *s)
{
	int	len;
	int	pad;
	int	count;

	len = 0;
	if (!s && !f->has_precision)
		s = "(null)";
	while (s && s[len] && (!f->has_precision || len < f->precision))
		++len;
	pad = 0;
	if (f->width > len)
		pad = f->width - len;
	count = 0;
	if (!(f->flags & FLAG_MINUS))
		count += ft_putnchar(' ', pad);
	count += write(1, s, len);
	if (f->flags & FLAG_MINUS)
		count += ft_putnchar(' ', pad);
	return (count);
}
