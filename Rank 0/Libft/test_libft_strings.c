/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_string_manipulation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:59:54 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 22:23:51 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "libft.h"

/* ---------------- BSD Replacement Functions ---------------- */
static size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len = strlen(src);
	if (size > 0)
	{
		size_t copy_len = (src_len >= size) ? size - 1 : src_len;
		memcpy(dst, src, copy_len);
		dst[copy_len] = '\0';
	}
	return src_len;
}

static size_t strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len = strlen(dst);
	size_t src_len = strlen(src);

	if (dst_len >= size)
		return size + src_len;

	size_t copy_len = size - dst_len - 1;
	if (copy_len > src_len)
		copy_len = src_len;

	memcpy(dst + dst_len, src, copy_len);
	dst[dst_len + copy_len] = '\0';
	return dst_len + src_len;
}

static const char* strnstr(const char *big, const char *little, size_t len)
{
	size_t little_len = strlen(little);
	if (little_len == 0)
		return big;

	for (size_t i = 0; i + little_len <= len && big[i]; i++)
	{
		if (strncmp(big + i, little, little_len) == 0)
			return big + i;
	}
	return NULL;
}

/* ---------------- Example inputs ---------------- */
static const char *TestStrings[] = {
		"", "a", "Hello", "42Porto", "  123", "special!@#", "NULL"
};

/* ---------------- Helper for printing string arrays ---------------- */
static void print_str_array(char **arr)
{
	printf("[ ");
	for (size_t i = 0; arr[i]; i++)
	{
		printf("\"%s\"", arr[i]);
		if (arr[i + 1])
			printf(", ");
	}
	printf(" ]\n");
}

/* ---------------- ft_atoi ---------------- */
static void RunAtoiTest(void)
{
	printf("=== Testing ft_atoi ===\n");
	const char *tests[] = {"0", "42", "-42", "2147483647", "-2147483648", "  \t\n 123", "abc", "", "+123"};
	for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
	{
		int my_result = ft_atoi(tests[i]);
		int std_result = atoi(tests[i]);
		printf("Input: \"%s\" -> ft_atoi: %d | atoi: %d\n", tests[i], my_result, std_result);
		assert(my_result == std_result);
	}
	printf("\n");
}

/* ---------------- ft_itoa ---------------- */
static void RunItoATest(void)
{
	printf("=== Testing ft_itoa ===\n");
	int nums[] = {0, 42, -42, INT_MAX, INT_MIN};
	for (size_t i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
	{
		char *str = ft_itoa(nums[i]);
		char buf[50];
		sprintf(buf, "%d", nums[i]);
		printf("ft_itoa(%d) = \"%s\"\n", nums[i], str);
		assert(strcmp(str, buf) == 0);
		free(str);
	}
	printf("\n");
}

/* ---------------- ft_strlen ---------------- */
static void RunStrlenTest(void)
{
	printf("=== Testing ft_strlen ===\n");
	for (size_t i = 0; i < sizeof(TestStrings)/sizeof(TestStrings[0]); i++)
	{
		const char *s = TestStrings[i];
		size_t my_len = ft_strlen(s);
		size_t std_len = strlen(s);
		printf("String: \"%s\" -> ft_strlen: %zu | strlen: %zu\n", s, my_len, std_len);
		assert(my_len == std_len);
	}
	printf("\n");
}

/* ---------------- ft_strlcpy ---------------- */
static void RunStrlcpyTest(void)
{
	printf("=== Testing ft_strlcpy ===\n");
	char buf[20];
	for (size_t i = 0; i < sizeof(TestStrings)/sizeof(TestStrings[0]); i++)
	{
		memset(buf, 'X', sizeof(buf));
		size_t my_ret = ft_strlcpy(buf, (char*)TestStrings[i], sizeof(buf));
		char buf2[20];
		memset(buf2, 'X', sizeof(buf2));
		size_t std_ret = strlcpy(buf2, TestStrings[i], sizeof(buf2));
		printf("Input: \"%s\" -> ft_strlcpy: \"%s\" | strlcpy: \"%s\"\n", TestStrings[i], buf, buf2);
		assert(strcmp(buf, buf2) == 0 && my_ret == std_ret);
	}
	printf("\n");
}

/* ---------------- ft_strlcat ---------------- */
static void RunStrlcatTest(void)
{
	printf("=== Testing ft_strlcat ===\n");
	char buf[50];
	char buf2[50];
	for (size_t i = 0; i < sizeof(TestStrings)/sizeof(TestStrings[0]); i++)
	{
		strcpy(buf, "start");
		strcpy(buf2, "start");
		size_t my_ret = ft_strlcat(buf, (char*)TestStrings[i], sizeof(buf));
		size_t std_ret = strlcat(buf2, TestStrings[i], sizeof(buf2));
		printf("Input: \"%s\" -> ft_strlcat: \"%s\" | strlcat: \"%s\"\n", TestStrings[i], buf, buf2);
		assert(strcmp(buf, buf2) == 0 && my_ret == std_ret);
	}
	printf("\n");
}

/* ---------------- ft_strchr & ft_strrchr ---------------- */
static void RunStrchrTest(void)
{
	printf("=== Testing ft_strchr & ft_strrchr ===\n");
	const char *s = "hello world";
	char chars[] = {'h', 'o', 'z', '\0', ' '};
	for (size_t i = 0; i < sizeof(chars)/sizeof(chars[0]); i++)
	{
		char c = chars[i];
		const char *my_ch = ft_strchr(s, c);
		const char *std_ch = strchr(s, c);
		const char *my_rch = ft_strrchr(s, c);
		const char *std_rch = strrchr(s, c);
		printf("Char '%c' -> ft_strchr: %s | strchr: %s\n", c, my_ch ? my_ch : "NULL", std_ch ? std_ch : "NULL");
		printf("Char '%c' -> ft_strrchr: %s | strrchr: %s\n", c, my_rch ? my_rch : "NULL", std_rch ? std_rch : "NULL");
		assert(my_ch == std_ch && my_rch == std_rch);
	}
	printf("\n");
}

/* ---------------- ft_strncmp ---------------- */
static void RunStrncmpTest(void)
{
	printf("=== Testing ft_strncmp ===\n");
	const char *pairs[][2] = {{"abc","abc"},{"abc","abcd"},{"abc","abd"},{"", ""}, {"a",""}};
	unsigned int ns[] = {0, 1, 2, 3, 5};
	for (size_t i = 0; i < sizeof(pairs)/sizeof(pairs[0]); i++)
		for (size_t j = 0; j < sizeof(ns)/sizeof(ns[0]); j++)
		{
			int my_res = ft_strncmp((char*)pairs[i][0], (char*)pairs[i][1], ns[j]);
			int std_res = strncmp(pairs[i][0], pairs[i][1], ns[j]);
			printf("ft_strncmp(\"%s\",\"%s\",%u) = %d | strncmp = %d\n", pairs[i][0], pairs[i][1], ns[j], my_res, std_res);
			assert((my_res == 0 && std_res == 0) || (my_res < 0 && std_res < 0) || (my_res > 0 && std_res > 0));
		}
	printf("\n");
}

/* ---------------- ft_strnstr ---------------- */
static void RunStrnstrTest(void)
{
	printf("=== Testing ft_strnstr ===\n");
	const char *big = "Hello 42 Porto";
	const char *little[] = {"Hello","42","Porto","X",""};
	size_t lens[] = {0, 5, 10, 20};
	for (size_t i = 0; i < sizeof(little)/sizeof(little[0]); i++)
		for (size_t j = 0; j < sizeof(lens)/sizeof(lens[0]); j++)
		{
			const char *my_res = strnstr(big, little[i], lens[j]);
			const char *ft_res = ft_strnstr(big, little[i], lens[j]);
			printf("ft_strnstr(\"%s\",\"%s\",%zu) -> %s | strnstr -> %s\n", big, little[i], lens[j], ft_res ? ft_res : "NULL", my_res ? my_res : "NULL");
			assert(ft_res == my_res);
		}
	printf("\n");
}

/* ---------------- ft_strdup ---------------- */
static void RunStrdupTest(void)
{
	printf("=== Testing ft_strdup ===\n");
	for (size_t i = 0; i < sizeof(TestStrings)/sizeof(TestStrings[0]); i++)
	{
		char *dup = ft_strdup((char*)TestStrings[i]);
		printf("Original: \"%s\" | ft_strdup: \"%s\"\n", TestStrings[i], dup);
		assert(strcmp(dup, TestStrings[i]) == 0);
		free(dup);
	}
	printf("\n");
}

/* ---------------- ft_substr ---------------- */
static void RunSubstrTest(void)
{
	printf("=== Testing ft_substr ===\n");
	const char *s = "Hello 42 Porto";
	unsigned int starts[] = {0, 6, 20};
	size_t lens[] = {5, 2, 10};
	for (size_t i = 0; i < sizeof(starts)/sizeof(starts[0]); i++)
		for (size_t j = 0; j < sizeof(lens)/sizeof(lens[0]); j++)
		{
			char *sub = ft_substr(s, starts[i], lens[j]);
			printf("ft_substr(\"%s\", %u, %zu) -> \"%s\"\n", s, starts[i], lens[j], sub);
			free(sub);
		}
	printf("\n");
}

/* ---------------- ft_strjoin ---------------- */
static void RunStrjoinTest(void)
{
	printf("=== Testing ft_strjoin ===\n");
	const char *s1 = "Hello";
	const char *s2 = "World";
	char *joined = ft_strjoin(s1, s2);
	printf("ft_strjoin(\"%s\",\"%s\") -> \"%s\"\n", s1, s2, joined);
	free(joined);
	printf("\n");
}

/* ---------------- ft_strtrim ---------------- */
static void RunStrtrimTest(void)
{
	printf("=== Testing ft_strtrim ===\n");
	const char *s1 = "  \tHello World  ";
	const char *set = " \t";
	char *trimmed = ft_strtrim(s1, set);
	printf("ft_strtrim(\"%s\", \"%s\") -> \"%s\"\n", s1, set, trimmed);
	free(trimmed);
	printf("\n");
}

/* ---------------- ft_split ---------------- */
static void RunSplitTest(void)
{
	printf("=== Testing ft_split ===\n");
	const char *s = "Hello 42 Porto";
	char **arr = ft_split(s, ' ');
	printf("ft_split(\"%s\", ' ') -> ", s);
	print_str_array(arr);
	// free array
	for (size_t i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	printf("\n");
}

/* ---------------- ft_striteri ---------------- */
static void to_upper_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void RunStriteriTest(void)
{
	printf("=== Testing ft_striteri ===\n");
	char s[] = "abcdef";
	ft_striteri(s, to_upper_index);
	printf("ft_striteri(\"abcdef\") -> \"%s\"\n", s);
	printf("\n");
}

/* ---------------- ft_strmapi ---------------- */
static char index_shift(unsigned int i, char c)
{
	return c + i;
}

static void RunStrmapiTest(void)
{
	printf("=== Testing ft_strmapi ===\n");
	const char *s = "abcd";
	char *mapped = ft_strmapi(s, index_shift);
	printf("ft_strmapi(\"%s\") -> \"%s\"\n", s, mapped);
	free(mapped);
	printf("\n");
}

/* ---------------- Main ---------------- */
int main(void)
{
	RunAtoiTest();
	RunItoATest();
	RunStrlenTest();
	RunStrlcpyTest();
	RunStrlcatTest();
	RunStrchrTest();
	RunStrncmpTest();
	RunStrnstrTest();
	RunStrdupTest();
	RunSubstrTest();
	RunStrjoinTest();
	RunStrtrimTest();
	RunSplitTest();
	RunStriteriTest();
	RunStrmapiTest();

	printf("All string manipulation tests passed!\n");
	return 0;
}
