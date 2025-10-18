/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:06:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/19 00:15:16 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
 * 	Variadic Arguments In C Work In An Interesting Way
 *		1. Declare it as va_list NAME;
 *		2. Declare where you start using it with va_start
 *		3. Extract Your Argument With va_arg(NAME, type) repeat till done
 *		4. Declare va_end(NAME) to close the Variadic arguments
 */

/*
static int	is_flag(char character)
{
	return (character == '#' || character == ' ' || character == '+'
		|| character == '0' || character == '-');
}

static void	handle_flags(void)
{
	return ;
}

static void	handle_values(const char* modifier)
{
	return ;
}
 */

/*
 * TODO:
 * 	%p The void * pointer argument has to be printed in hexadecimal format.
	%u Prints an unsigned decimal (base 10) number.
	%x Prints a number in hexadecimal (base 16) lowercase format.
	%X Prints a number in hexadecimal (base 16) uppercase format.

 	if(has_modifiers())
		return;
 */
static int	parse_to_buffer(const char *format, va_list *args, char *buffer)
{
	int	optionlength;

	++format;
	if (*format == 'c')
		ft_putchar_fd((char)va_arg(*args, int), 1);
	if (*format == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1);
	if (*format == 'u')
		ft_put_unsigned_nbr_rec(va_arg(*args, unsigned int), 1);
	if (*format == '%')
		ft_putchar_fd('%', 1);
	optionlength = 2;
	++buffer;
	return (optionlength);
}

/*
 * 	We use this to parse and print specific things
 *
 * 	TODO: Who knows what they'll use to test this so 1024 might be low? Gods know
 */
static void	print_string_with_arguments(const char *format, va_list args)
{
	char	buffer[MAX_BUFFER_SIZE];

	ft_memset(buffer, 0, sizeof(buffer));
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			++format;
			continue ;
		}
		format += parse_to_buffer(format, &args, buffer);
		ft_putstr_fd(buffer, 1);
	}
}

/*
 * 	C's printf equivalent, we dont do buffer management, we print straight
 * 		away with write(); Makes it easy enough and noone seems like they'd
 * 		complain? :3
 *
 * 	Supports the following:
 * 		%c Prints a single character.
 * 		%s Prints a string (as defined by the common C convention).
 * 		%p The void * pointer argument has to be printed in hexadecimal format.
 * 		%d Prints a decimal (base 10) number.
 * 		%i Prints an integer in base 10.
 * 		%u Prints an unsigned decimal (base 10) number.
 * 		%x Prints a number in hexadecimal (base 16) lowercase format.
 * 		%X Prints a number in hexadecimal (base 16) uppercase format.
 * 		%% Prints a percent sign
 *
 * 	Supports one/multiple flags after % symbol
 * 		#	- Converts To A Type x/X is hex, o to octal, f for floats
 * 		' ' - Applies a ' ' where the + should be for signess
 * 		+	- Applies the + sign, normally only - is show applies to numerics
 * 		0	- Pads numbers with 0's before it like 010 pads 0s to the left
 * 			  of number number is included
 * 		-	- Justified Text? // TODO:
 *
 * 	Returnss the number of bytes printed
 *
 * 	Sauce: https://man7.org/linux/man-pages/man3/printf.3.html
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start (args, format);
	print_string_with_arguments(format, args);
	va_end(args);
	return (0);
}

/*
 * if (*format != '%')
			ft_putchar_fd(*format, 1);
		if (is_flag(*format + 1))
			handle_flags();
		else
			handle_values();
 */

/*

va_list args;           // Declare a variable to hold the argument list
va_start(args, format); // Initialize it, format is the last named parameter

// Example: get an int
int i = va_arg(args, int);

// Example: get a double
double d = va_arg(args, double);

// When done
va_end(args);

 */