/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:07:58 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/10 19:19:35 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n);

/*
 * This just uses memset as the standard has deprecated this and instead this
 * is essentially just a memset wrapper
 * https://man7.org/linux/man-pages/man3/bzero.3.html
 * https://linux.die.net/man/3/bzero
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
