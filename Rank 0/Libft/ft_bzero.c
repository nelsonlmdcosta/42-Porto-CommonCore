/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:07:58 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 16:29:56 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	bzero() is considered obsolete in POSIX and is typically
 * 		replaced by memset() with a value of 0.
 *
 * 	https://man7.org/linux/man-pages/man3/bzero.3.html
 * 	https://linux.die.net/man/3/bzero
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
