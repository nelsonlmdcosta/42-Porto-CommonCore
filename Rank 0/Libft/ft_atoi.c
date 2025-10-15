/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:10:54 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 22:59:28 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Takes Into Consideration The Following
 * 		'\t’ - Horizontal tabulator
 * 		'\n’ - Line feed
 * 		'\v’ - Vertical tabulator
 * 		'\f’ - Page feed
 * 		'\r’ - Carriage return
 * 		' '  - Space
 */
static int	ft_isspace(const char character)
{
	return ((character >= 9 && character <= 13) || character == 32);
}

/*
 * Run-of-the-mill atoi, ignores all white spaces,
 * 		then deals with signage,
 * 		then converts a string value into a number
 *
 * 	Note: Hate the short naming conventions but it's needed because of
 * 		dumbass norminettes silly limitations >_>
 *
 * 	https://man7.org/linux/man-pages/man3/atoi.3.html
 */
int	ft_atoi(const char *s)
{
	int	sign;
	int	result;

	sign = 1;
	while (ft_isspace(*s))
		++s;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		++s;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = (result * 10) + (*s - '0');
		++s;
	}
	return (result * sign);
}
