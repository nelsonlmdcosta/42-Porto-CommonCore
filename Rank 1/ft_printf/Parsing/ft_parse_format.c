/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:27:06 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/28 07:21:28 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 *	Checks To See If Any Of The Supported Flags Are Found
 *
 *	TODO: Make This Into The If Statement Below And Return The Actual Flag
 *		Value? Should Simplify THe Code
 */
static int	ft_isflag(char character)
{
	return (character == '-' || character == '0' || character == '#'
		|| character == ' ' || character == '+');
}

/*
 * 	Parses Out The Simples Flags Into The Structure
 */
static int	ft_parse_format_flags(const char *format, t_format_info *fmtinfo)
{
	int count;

	count = 0;
	while (ft_isflag(format[count]))
	{
		if (format[count] == '-')
			fmtinfo->flags |= FLAG_MINUS;
		else if (format[count] == '0')
			fmtinfo->flags |= FLAG_ZERO;
		else if (format[count] == '#')
			fmtinfo->flags |= FLAG_HASH;
		else if (format[count] == ' ')
			fmtinfo->flags |= FLAG_SPACE;
		else if (format[count] == '+')
			fmtinfo->flags |= FLAG_PLUS;
		++count;
	}
	return (count);
}

/*
 * 	Parses The Precision Format Flag If It Exists
 */
static int	ft_parse_format_precision(const char *format, t_format_info *fmtinfo)
{
	int	count;

	count = 0;
	if (format[count] == '.')
	{
		fmtinfo->has_precision = 1;
		count++;
		while (ft_isdigit((unsigned char)format[count]))
			fmtinfo->precision = fmtinfo->precision * 10 + (format[count++] - '0');
	}
	return (count);
}

/*
 * 	We Just Need To Initialize The Cached Structure From The Main Entry Point
 * 		Ensure It's Nice And Zero'd out.
 *
 * 	We Then Use BitShifted Values To Represent Our Flags, As A Flag Has No
 * 		Reason To Be Bigger Than A Single Bit, Flags Also Need To Be Before
 * 		Any Specifier.
 *
 * 	We Then Look For Some Integers, If So We Construct The Width Of The
 * 		Desired String And Save That Width.
 *
 * 	Finally Check Against The Precision. Before Pulling Out The Actual Specifier
 * 		For Our Printing Portion.
 *
 * 	This structure will help consolidate and keep all the important information
 * 		Together in a tightly packed data structure for later use, helps that
 * 		this step has to kinda be done first too, as these modifiers are at
 * 		the start.
 *
 * 	Returns the number of characters parsed through.
 *
 * 	https://cplusplus.com/reference/cstdio/printf
 */
int	ft_parse_format(const char *format, t_format_info *fmtinfo)
{
	int	count;

	count = 0;
	ft_memset(fmtinfo, 0, sizeof(*fmtinfo));
	count += ft_parse_format_flags(format + count, fmtinfo);
	while (ft_isdigit((unsigned char)format[count]))
		fmtinfo->width = fmtinfo->width * 10 + (format[count++] - '0');
	count += ft_parse_format_precision(format + count, fmtinfo);
	if (format[count])
		fmtinfo->specifier = format[count++];
	return (count);
}