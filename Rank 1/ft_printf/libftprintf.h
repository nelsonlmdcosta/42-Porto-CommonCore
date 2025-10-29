/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:12:38 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/28 15:48:34 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FLAG_MINUS  (1 << 0)
# define FLAG_ZERO   (1 << 1)
# define FLAG_HASH   (1 << 2)
# define FLAG_SPACE  (1 << 3)
# define FLAG_PLUS   (1 << 4)

/*
 * Dont mind me just here to try keep my windows machine as close to what
 * The School Uses, Windows for backwards compatibility makes it's longs in
 * c 32 bits rather than 64 x) So if i define my own technically it's ok
 *
 * Source is at MSDN Predefined Macros Page, damn link is too long >_>
 * #GodblessNorminette :)
 *
 * // Take this one that's easier to parse through
 * https://blog.kowalczyk.info/article/j/
 * guide-to-predefined-macros-in-c-compilers-gcc-clang-msvc-etc..html
 */
#ifndef T_LONG_H
# define T_LONG_H
# if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__)
typedef long long long64;
# else
typedef long long64;
# endif
#endif

#ifndef T_ULONG_H
# define T_ULONG_H
# if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__)
typedef unsigned long long ulong64;
# else
typedef unsigned long ulong64;
# endif
#endif

typedef struct s_format_info
{
	unsigned int	flags;
	int				width;
	int				precision;
	int				has_precision;
	char			specifier;
}	t_format_info;

int		ft_printf(const char *fmt, ...);
int		ft_parse_format(const char *format, t_format_info *fmtinfo);
int		dispatch_format(t_format_info *f, va_list *args);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnchar(char c, int n);
int		ft_numberlength(ulong64 n, int base);

int		ft_print_char(t_format_info *format_info, char c);
int		ft_print_str(t_format_info *f, char *s);
int		print_number(t_format_info *f, int n);
int		print_unsigned(t_format_info *f, unsigned int n);
int		print_hex(t_format_info *f, unsigned int n, int upper);
int		print_ptr(t_format_info *f, void *ptr);

#endif
