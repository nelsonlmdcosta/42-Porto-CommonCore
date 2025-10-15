/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_fildescriptors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:20:19 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 23:16:58 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/* ---------------- ft_putchar_fd ---------------- */
static void RunPutcharFdTest(void)
{
	write(1, "=== Testing ft_putchar_fd ===\n", ft_strlen("=== Testing ft_putchar_fd ===\n"));
	write(1, "Output to stdout: ", ft_strlen("Output to stdout: "));
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	write(1, "Output to stderr: ", ft_strlen("Output to stderr: "));
	ft_putchar_fd('B', 2);
	ft_putchar_fd('\n', 2);
	write(1, "\n", 1);
}

/* ---------------- ft_putstr_fd ---------------- */
static void RunPutstrFdTest(void)
{
	printf("=== Testing ft_putstr_fd ===\n");
	ft_putstr_fd("Hello stdout!\n", 1);
	ft_putstr_fd("Hello stderr!\n", 2);

	printf("Test NULL input (should do nothing):\n");
	ft_putstr_fd(NULL, 1);
	printf("Done\n\n");
}

/* ---------------- ft_putendl_fd ---------------- */
static void RunPutendlFdTest(void)
{
	printf("=== Testing ft_putendl_fd ===\n");
	ft_putendl_fd("Hello with newline!", 1);
	ft_putendl_fd("Hello stderr newline!", 2);

	printf("Test NULL input (should do nothing):\n");
	ft_putendl_fd(NULL, 1);
	printf("Done\n\n");
}

/* ---------------- ft_putnbr_fd ---------------- */
static void RunPutnbrFdTest(void)
{
	printf("=== Testing ft_putnbr_fd ===\n");
	int numbers[] = {0, 42, -42, 123456, -2147483648, 2147483647};

	for (size_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
	{
		printf("ft_putnbr_fd(%d) -> ", numbers[i]);
		ft_putnbr_fd(numbers[i], 1);
		printf("\n");
	}
	printf("\n");
}

/* ---------------- Main ---------------- */
int main(void)
{
	RunPutcharFdTest();
	RunPutstrFdTest();
	RunPutendlFdTest();
	RunPutnbrFdTest();

	printf("All _fd function tests executed!\n");
	return 0;
}
