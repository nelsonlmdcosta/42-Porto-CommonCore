/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:14:56 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/19 00:09:35 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_rec(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)-n;
	}
	ft_putnbr_rec(num, fd);
}
