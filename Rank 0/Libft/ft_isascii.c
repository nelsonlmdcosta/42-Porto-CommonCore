/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:57:15 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/10 12:03:53 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Validates If A Character is Considered An Ascii Character
 *		Does not check for extended ascii
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
