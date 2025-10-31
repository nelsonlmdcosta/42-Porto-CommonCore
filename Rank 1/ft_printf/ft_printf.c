/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:06:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/31 16:50:40 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * 	Calls Through To The Actual Function That Will Need To Handle The Actual
 * 		Printing With Specific Flags, Note These Flags have Already Been Parsed
 * 		At tHis Time Using The parse_format function, cleanest way I could
 * 		think of doing it
 * 	Worth Noting That It Seems On Linux You DONT Need To Send The Pointer For
 * 		va_list However I work on Windows for the most part till I test on the
 * 		Schools computers which means that I do infact need a pointer to keep
 * 		it as cross platformy as possible. Makes my life easier
 */
int	dispatch_format(t_format_info *f, va_list *args)
{
	if (f->specifier == 'c')
		return (ft_print_char(f, va_arg(*args, int)));
	if (f->specifier == 's')
		return (ft_print_str(f, va_arg(*args, char *)));
	if (f->specifier == 'p')
		return (ft_print_ptr(f, va_arg(*args, void *)));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (ft_print_number(f, va_arg(*args, int)));
	if (f->specifier == 'u')
		return (ft_print_unsigned(f, va_arg(*args, unsigned int)));
	if (f->specifier == 'x')
		return (ft_print_hex(f, va_arg(*args, unsigned int), 0));
	if (f->specifier == 'X')
		return (ft_print_hex(f, va_arg(*args, unsigned int), 1));
	if (f->specifier == '%')
		return (ft_putnchar('%', 1));
	return (0);
}

/*
 * 	The Entry Point Doesn't Do Anything Special Really, Just Takes In The
 * 		Format And Variadic Arguments ANd Tries To Parse The Format For A
 * 		Given Complex Type, Then Sends Them Along To The Printers Through
 * 		A Very Crude Example Of A Dispatcher
 *
 * 	Supports All Flags Requested
 * 		"-" - Left Justify 			Applies to [c,s,d,x]
 * 		"+" - Show positive numebrs Applies to [d,i]
 * 		" " - Space, instead of +	Applies to [d,i] if no plus exists
 * 		"0" - Pads with 0's needs n Applies to [d,i,x,X,u,p] if no - exists
 * 		"#" - Show as Hex			Applies to [x,X]
 * 		"." - Num digits or c/s len Applies to [s,d,i,u,x,X]
 */
int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_format_info	f;
	int				total_printed;
	int				skip;

	total_printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			ft_memset(&f, 0, sizeof(f));
			skip = ft_parse_format(++format, &f);
			format += skip;
			total_printed += dispatch_format(&f, &args);
			continue ;
		}
		total_printed += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (total_printed);
}
