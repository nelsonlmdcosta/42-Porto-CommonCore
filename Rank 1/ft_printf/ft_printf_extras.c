/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:12:27 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/19 00:15:42 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_unsigned_nbr_rec(unsigned int n, int fd)
{
	if (n >= 10)
		ft_put_unsigned_nbr_rec(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
