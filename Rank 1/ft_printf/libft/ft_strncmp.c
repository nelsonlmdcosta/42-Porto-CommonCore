/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:09:56 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/17 17:26:03 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Strncmp, needs to check explicitly for no n = 0 and does essencially
 * 	what strcmp does.
 */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
