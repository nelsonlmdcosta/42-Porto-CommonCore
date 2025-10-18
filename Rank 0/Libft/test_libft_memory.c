/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:20:03 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/18 19:15:01 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "libft.h"

/* ---------------- ft_bzero ---------------- */
static void RunBzeroTest(void)
{
	printf("=== Testing ft_bzero ===\n");
	char buf[10];

	for (size_t n = 0; n <= sizeof(buf); n++)
	{
		memset(buf, 'X', sizeof(buf));
		ft_bzero(buf, n);

		int zeroed = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (buf[i] != 0)
				zeroed = 0;
		}
		printf("ft_bzero(buf, %zu) -> first %zu bytes zeroed? %s\n", n, n, zeroed ? "yes" : "no");
		assert(zeroed);
	}
	printf("\n");
}

/* ---------------- ft_memset ---------------- */
static void RunMemsetTest(void)
{
	printf("=== Testing ft_memset ===\n");
	char buf[10];

	for (size_t n = 0; n <= sizeof(buf); n++)
	{
		ft_memset(buf, 'A', n);
		int correct = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (buf[i] != 'A')
				correct = 0;
		}
		printf("ft_memset(buf, 'A', %zu) -> correct? %s\n", n, correct ? "yes" : "no");
		assert(correct);
	}
	printf("\n");
}

/* ---------------- ft_calloc ---------------- */
static void RunCallocTest(void)
{
	printf("=== Testing ft_calloc ===\n");
	size_t num = 5, size = sizeof(int);
	int *arr = ft_calloc(num, size);
	assert(arr != NULL);
	int zeroed = 1;
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] != 0)
			zeroed = 0;
	}
	printf("ft_calloc(%zu, %zu) -> zeroed? %s\n", num, size, zeroed ? "yes" : "no");
	free(arr);
	printf("\n");
}

/* ---------------- ft_memcpy ---------------- */
static void RunMemcpyTest(void)
{
	printf("=== Testing ft_memcpy ===\n");
	char src[10] = "abcdefghi";
	char dst[10] = {0};
	ft_memcpy(dst, src, 9);
	printf("ft_memcpy -> dst: \"%s\"\n", dst);
	assert(memcmp(dst, src, 9) == 0);
	printf("\n");
}

/* ---------------- ft_memmove ---------------- */
static void RunMemmoveTest(void)
{
	printf("=== Testing ft_memmove ===\n");
	char buf[20] = "1234567890";
	// overlapping move: move first 5 chars to index 3
	ft_memmove(buf + 3, buf, 5);
	printf("ft_memmove overlapping -> buf: \"%s\"\n", buf);
	char expected[] = "1231234590";
	assert(memcmp(buf, expected, 10) == 0);
	printf("\n");
}

/* ---------------- ft_memchr ---------------- */
static void RunMemchrTest(void)
{
	printf("=== Testing ft_memchr ===\n");
	char buf[] = "abcdef";
	for (size_t i = 0; i < strlen(buf); i++)
	{
		const void *my_res = ft_memchr(buf, buf[i], strlen(buf));
		const void *std_res = memchr(buf, buf[i], strlen(buf));
		printf("ft_memchr('%c') -> %c | memchr -> %c\n", buf[i], *((char*)my_res), *((char*)std_res));
		assert(my_res == std_res);
	}
	// searching for non-existent value
	assert(ft_memchr(buf, 'z', strlen(buf)) == memchr(buf, 'z', strlen(buf)));
	printf("\n");
}

/* ---------------- ft_memcmp ---------------- */
static void RunMemcmpTest(void)
{
	printf("=== Testing ft_memcmp ===\n");
	char buf1[] = "abcdef";
	char buf2[] = "abcdeg";
	int my_res = ft_memcmp(buf1, buf2, 6);
	int std_res = memcmp(buf1, buf2, 6);
	printf("ft_memcmp -> %d | memcmp -> %d\n", my_res, std_res);
	assert((my_res == 0 && std_res == 0) || (my_res < 0 && std_res < 0) || (my_res > 0 && std_res > 0));
	printf("\n");
}

/* ---------------- Main ---------------- */
int main(void)
{
	RunBzeroTest();
	RunMemsetTest();
	RunCallocTest();
	RunMemcpyTest();
	RunMemmoveTest();
	RunMemchrTest();
	RunMemcmpTest();

	printf("All memory function tests passed!\n");
	return 0;
}
