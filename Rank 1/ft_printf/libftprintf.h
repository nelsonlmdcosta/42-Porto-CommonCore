/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:12:38 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/19 00:14:46 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define MAX_BUFFER_SIZE 1024

int		ft_printf(const char *format, ...);

void	ft_put_unsigned_nbr_rec(unsigned int n, int fd);

#endif