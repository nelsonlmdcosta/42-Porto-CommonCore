/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:12:38 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/27 18:51:20 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

/* bitmask flags */
# define FLAG_MINUS  (1 << 0)
# define FLAG_ZERO   (1 << 1)
# define FLAG_HASH   (1 << 2)
# define FLAG_SPACE  (1 << 3)
# define FLAG_PLUS   (1 << 4)

typedef struct s_format_info
{
	uint8_t	flags;
	int		width;
	int		precision;
	int		has_precision;
	char	specifier;
}	t_format_info;

int		ft_printf(const char *fmt, ...);
int		parse_format(const char *format, t_format_info *fmtinfo);
int		dispatch_format(t_format_info *f, va_list *args);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnchar(char c, int n);
int		ft_numlen(unsigned long n, int base);

int		print_char(t_format_info *f, char c);
int		print_str(t_format_info *f, char *s);
int		print_nbr(t_format_info *f, int n);
int		print_unsigned(t_format_info *f, unsigned int n);
int		print_hex(t_format_info *f, unsigned int n, int upper);
int		print_ptr(t_format_info *f, void *ptr);

#endif
