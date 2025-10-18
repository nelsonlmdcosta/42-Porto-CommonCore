/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:50:39 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/18 23:59:53 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:50:39 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/18 22:36:41 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

void test_char(void)
{
	printf("----- %%c test \"-----\n");
	printf("Expected: printf   : |%c| |%c| |%c|\n", 'A', ' ', 0);
	printf("Actual  : ft_printf: |");
	fflush(stdout);
	ft_printf("%c| |%c| |%c|\n", 'A', ' ', 0);
	printf("\n\n");
	fflush(stdout);
}

void test_string(void)
{
	char *str = "Hello, world!";
	char *empty = "";
	char *null_str = NULL;

	printf("----- %%s test -----\n");
	printf("Expected: printf   : |%s| |%s| |%s|\n", str, empty, null_str);
	printf("Actual  : ft_printf: |");
	fflush(stdout);
	ft_printf("%s| |%s| |%s|\n", str, empty, null_str);
	printf("\n\n");
	fflush(stdout);
}

void test_pointer(void)
{
	int x = 42;
	void *ptr = &x;
	void *null_ptr = NULL;

	printf("----- %%p test -----\n");
	printf("Expected: printf   : |%p| |%p|\n", ptr, null_ptr);
	printf("Actual  : ft_printf: |");
	fflush(stdout);
	ft_printf("%p| |%p|\n", ptr, null_ptr);
	printf("\n\n");
	fflush(stdout);
}

void test_ints(void)
{
	int nums[] = {0, 42, -42, INT_MAX, INT_MIN};

	printf("----- %%d/%%i test -----\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Expected: printf   : |%d| |%i|\n", nums[i], nums[i]);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%d| |%i|\n", nums[i], nums[i]);
	}
	printf("\n\n");
	fflush(stdout);
}

void test_unsigned(void)
{
	unsigned int u_nums[] = {0, 42, UINT_MAX};

	printf("----- %%u test -----\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Expected: printf   : |%u|\n", u_nums[i]);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%u|\n", u_nums[i]);
	}
	printf("\n\n");
	fflush(stdout);
}

void test_hex(void)
{
	unsigned int hex_nums[] = {0, 42, 255, UINT_MAX};

	printf("----- %%x/%%X test -----\n");
	for (int i = 0; i < 4; i++)
	{
		printf("Expected: printf   : |%x| |%X|\n", hex_nums[i], hex_nums[i]);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%x| |%X|\n", hex_nums[i], hex_nums[i]);
	}
	printf("\n\n");
	fflush(stdout);
}

void test_percent(void)
{
	printf("----- %% test -----\n");
	printf("Expected: printf   : %% %% %%\n");
	printf("Actual  : ft_printf: ");
	fflush(stdout);
	ft_printf("%% %% %%\n");
	printf("\n\n");
	fflush(stdout);
}

void test_mixed(void)
{
	int x = 42;

	printf("----- Mixed formatting test -----\n");
	printf("Expected: printf   : char=%c, str=%s, ptr=%p, dec=%d, hex=%X, percent=%%\n", 'Z', "test", (void*)&x, -123, 255);
	printf("Actual  : ft_printf: ");
	fflush(stdout);
	ft_printf("char=%c, str=%s, ptr=%p, dec=%d, hex=%X, percent=%%\n", 'Z', "test", &x, -123, 255);
	printf("\n\n");
	fflush(stdout);
}

int main(void)
{
	printf("=== FT_PRINTF TESTS ===\n\n");

	test_char();
	test_string();
	test_pointer();
	test_ints();
	test_unsigned();
	test_hex();
	test_percent();
	test_mixed();

	printf("=== END OF TESTS ===\n");
	return 0;
}
