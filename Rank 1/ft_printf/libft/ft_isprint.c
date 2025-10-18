/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:57:57 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/10 12:03:59 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Checks To See If Character Is Printable Character AKA
 *		Uppercase Letters
 *		Lowercase Letters
 *		Numerics
 *		Special Characters
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
