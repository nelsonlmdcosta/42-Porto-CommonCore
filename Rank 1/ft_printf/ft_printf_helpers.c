/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:39:54 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/18 23:55:59 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char *to_hex(unsigned long num, int uppercase)
{
	char *hex_chars = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	char buffer[17]; // 16 digits max for 64-bit + null terminator
	buffer[16] = '\0';

	int i = 15;
	if (num == 0)
	{
		buffer[i--] = '0';
	}
	while (num != 0)
	{
		buffer[i--] = hex_chars[num % 16];
		num /= 16;
	}

	// Allocate and copy result
	char *result = malloc(17 - i);
	if (!result)
		return (NULL);

	int j = 0;
	i++; // move to first filled digit
	while (buffer[i])
		result[j++] = buffer[i++];
	result[j] = '\0';

	return result;
}*/
void	temp(void)
{
}
