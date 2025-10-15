/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:21:01 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 23:14:18 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include "libft.h"

static int TestChars[] = {
		'A', 'Z', 'a', 'z', '0', '9', '!', ' ', '\n', 127, -1, 128
};

static void RunIsAlnumTest(void)
{
	printf("=== Testing ft_isalnum ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_isalnum(c);
		int std_result = isalnum(c);
		printf("Char: %c -> ft_isalnum: %d | isalnum: %d\n", c, my_result != 0, std_result != 0);
		assert((my_result != 0) == (std_result != 0));
	}
	printf("\n");
}

static void RunIsAlphaTest(void)
{
	printf("=== Testing ft_isalpha ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_isalpha(c);
		int std_result = isalpha(c);
		printf("Char: %c -> ft_isalpha: %d | isalpha: %d\n", c, my_result != 0, std_result != 0);
		assert((my_result != 0) == (std_result != 0));
	}
	printf("\n");
}

static void RunIsAsciiTest(void)
{
	printf("=== Testing ft_isascii ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_isascii(c);
		int std_result = isascii(c);
		printf("Char: %c -> ft_isascii: %d | isascii: %d\n", c, my_result != 0, std_result != 0);
		assert((my_result != 0) == (std_result != 0));
	}
	printf("\n");
}

static void RunIsDigitTest(void)
{
	printf("=== Testing ft_isdigit ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_isdigit(c);
		int std_result = isdigit(c);
		printf("Char: %c -> ft_isdigit: %d | isdigit: %d\n", c, my_result != 0, std_result != 0);
		assert((my_result != 0) == (std_result != 0));
	}
	printf("\n");
}

static void RunIsPrintTest(void)
{
	printf("=== Testing ft_isprint ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_isprint(c);
		int std_result = isprint(c);
		printf("Char: %c -> ft_isprint: %d | isprint: %d\n", c, my_result != 0, std_result != 0);
		assert((my_result != 0) == (std_result != 0));
	}
	printf("\n");
}

static void RunToLowerTest(void)
{
	printf("=== Testing ft_tolower ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_tolower(c);
		int std_result = tolower(c);
		printf("Char: %c -> ft_tolower: %c | tolower: %c\n", c, my_result, std_result);
		assert(my_result == std_result);
	}
	printf("\n");
}

static void RunToUpperTest(void)
{
	printf("=== Testing ft_toupper ===\n");

	for (size_t i = 0; i < sizeof(TestChars)/sizeof(TestChars[0]); i++)
	{
		int c = TestChars[i];
		int my_result = ft_toupper(c);
		int std_result = toupper(c);
		printf("Char: %c -> ft_toupper: %c | toupper: %c\n", c, my_result, std_result);
		assert(my_result == std_result);
	}
	printf("\n");
}

int main(void)
{
	RunIsAlnumTest();
	RunIsAlphaTest();
	RunIsAsciiTest();
	RunIsDigitTest();
	RunIsPrintTest();
	RunToLowerTest();
	RunToUpperTest();

	printf("All character manipulation tests passed!\n");
	return 0;
}
