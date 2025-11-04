/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:50:39 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/11/01 10:51:33 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

void test_char(void)
{
	char test_chars[] = {'A', ' ', 0, '\n'};

	printf("----- %%c tests -----\n");

	for (size_t i = 0; i < sizeof(test_chars)/sizeof(test_chars[0]); i++)
	{
		char c = test_chars[i];

		// width 0
		printf("Expected: printf   : |%c|\n", c);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%c|\n", c);

		// width 3 right-justify
		printf("Expected: printf   : |%3c|\n", c);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%3c|\n", c);

		// width 3 left-justify
		printf("Expected: printf   : |%-3c|\n", c);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%-3c|\n", c);

		// width 5 right-justify
		printf("Expected: printf   : |%5c|\n", c);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%5c|\n", c);

		// width 5 left-justify
		printf("Expected: printf   : |%-5c|\n", c);
		fflush(stdout);
		ft_printf("Actual : ft_printf : |%-5c|\n", c);

		printf("\n");
	}
}

void test_string(void)
{
	char *strings[] = {"Hello", "", NULL, "Hi"};

	printf("----- %%s tests -----\n");

	for (size_t i = 0; i < sizeof(strings)/sizeof(strings[0]); i++)
	{
		char *s = strings[i];

		// width 0, default precision
		printf("Expected: printf   : |%s|\n", s);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%s|\n", s);

		// width 5
		printf("Expected: printf   : |%5s|\n", s);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%5s|\n", s);

		// width 5 left-justify
		printf("Expected: printf   : |%-5s|\n", s);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%-5s|\n", s);

		// precision 3
		printf("Expected: printf   : |%.3s|\n", s);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%.3s|\n", s);

		// width 5 + precision 3
		printf("Expected: printf   : |%5.3s|\n", s);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%5.3s|\n", s);

		// left-justify + precision 3
		printf("Expected: printf   : |%-5.3s|\n", s);
		printf("Actual  : ft_printf: |");
		fflush(stdout);
		ft_printf("%-5.3s|\n", s);

		printf("\n");
	}
}

void test_percent(void)
{
	printf("----- %%%% tests -----\n");

	printf("Expected: printf   : |%%|\n");
	fflush(stdout);
	ft_printf("Actual  : ft_printf: |%%|\n");

	printf("\n");
}

void test_ints(void)
{
	int nums[] = {0, 42, -42, INT_MAX, INT_MIN};

	printf("----- %%d/%%i tests -----\n");

	for (size_t i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
	{
		int n = nums[i];

		// default
		printf("Expected: printf   : |%d| |%i|\n", n, n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%d| |%i|\n", n, n);

		// width 5 right-justify
		printf("Expected: printf   : |%5d| |%5i|\n", n, n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%5d| |%5i|\n", n, n);

		// width 5 left-justify
		printf("Expected: printf   : |%-5d| |%-5i|\n", n, n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%-5d| |%-5i|\n", n, n);

		// zero-padded width 5
		printf("Expected: printf   : |%05d| |%05i|\n", n, n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%05d| |%05i|\n", n, n);

		printf("\n");
	}

	printf("\n");
	fflush(stdout);
}

void test_unsigned(void)
{
	unsigned int u_nums[] = {0, 42, UINT_MAX};

	printf("----- %%u tests -----\n");

	for (size_t i = 0; i < sizeof(u_nums)/sizeof(u_nums[0]); i++)
	{
		unsigned int n = u_nums[i];

		// default
		printf("Expected: printf   : |%u|\n", n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%u|\n", n);

		// width 5 right-justify
		printf("Expected: printf   : |%5u|\n", n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%5u|\n", n);

		// width 5 left-justify
		printf("Expected: printf   : |%-5u|\n", n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%-5u|\n", n);

		// zero-padded width 5
		printf("Expected: printf   : |%05u|\n", n);
		fflush(stdout);
		ft_printf("Actual  : ft_printf: |%05u|\n", n);

		printf("\n");
	}

	printf("\n");
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
	test_percent();

	test_ints();
	test_unsigned();

	test_hex();
	test_pointer();

	test_mixed();

	printf("=== END OF TESTS ===\n");
	return 0;
}
