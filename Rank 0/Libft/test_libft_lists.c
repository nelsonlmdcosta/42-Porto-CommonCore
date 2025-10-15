/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:20:33 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 23:35:14 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libft.h"

/* ---------------- Helper functions for testing ---------------- */
static void del_int(void *content)
{
	free(content);
}

static void print_list(t_list *lst)
{
	printf("[ ");
	while (lst)
	{
		printf("%s", (char*)lst->content);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf(" ]\n");
}

static void increment_content(void *content)
{
	int *p = (int*)content;
	(*p)++;
}

static void *duplicate_content(void *content)
{
	int *p = (int*)content;
	int *dup = malloc(sizeof(int));
	if (!dup)
		return NULL;
	*dup = *p * 2;
	return dup;
}

/* ---------------- ft_lstnew ---------------- */
static void RunLstNewTest(void)
{
	printf("=== Testing ft_lstnew ===\n");
	char *str = "hello";
	t_list *node = ft_lstnew(str);
	assert(node != NULL);
	assert(strcmp((char*)node->content, "hello") == 0);
	assert(node->next == NULL);
	printf("ft_lstnew(\"hello\") -> node content: %s | next: %p\n", (char*)node->content, node->next);
	free(node);
	printf("\n");
}

/* ---------------- ft_lstadd_front & ft_lstsize ---------------- */
static void RunLstAddFrontAndSizeTest(void)
{
	printf("=== Testing ft_lstadd_front & ft_lstsize ===\n");
	t_list *lst = NULL;

	char *data1 = "first";
	char *data2 = "second";

	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);

	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);

	print_list(lst);
	assert(ft_lstsize(lst) == 2);
	printf("List size: %d\n", ft_lstsize(lst));

	ft_lstclear(&lst, NULL);
	printf("\n");
}

/* ---------------- ft_lstlast ---------------- */
static void RunLstLastTest(void)
{
	printf("=== Testing ft_lstlast ===\n");
	t_list *lst = ft_lstnew("A");
	ft_lstadd_back(&lst, ft_lstnew("B"));
	ft_lstadd_back(&lst, ft_lstnew("C"));

	t_list *last = ft_lstlast(lst);
	assert(strcmp((char*)last->content, "C") == 0);
	printf("Last node content: %s\n", (char*)last->content);

	ft_lstclear(&lst, NULL);
	printf("\n");
}

/* ---------------- ft_lstadd_back ---------------- */
static void RunLstAddBackTest(void)
{
	printf("=== Testing ft_lstadd_back ===\n");
	t_list *lst = ft_lstnew("X");
	ft_lstadd_back(&lst, ft_lstnew("Y"));
	ft_lstadd_back(&lst, ft_lstnew("Z"));

	print_list(lst);
	assert(ft_lstsize(lst) == 3);

	ft_lstclear(&lst, NULL);
	printf("\n");
}

/* ---------------- ft_lstdelone ---------------- */
static void RunLstDelOneTest(void)
{
	printf("=== Testing ft_lstdelone ===\n");
	int *val = malloc(sizeof(int));
	*val = 42;
	t_list *node = ft_lstnew(val);

	ft_lstdelone(node, del_int);
	printf("ft_lstdelone executed.\n\n");
}

/* ---------------- ft_lstclear ---------------- */
static void RunLstClearTest(void)
{
	printf("=== Testing ft_lstclear ===\n");
	t_list *lst = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("three")));

	print_list(lst);
	ft_lstclear(&lst, del_int);
	assert(lst == NULL);
	printf("ft_lstclear executed. List is NULL.\n\n");
}

/* ---------------- ft_lstiter ---------------- */
static void RunLstIterTest(void)
{
	printf("=== Testing ft_lstiter ===\n");
	int a = 1, b = 2, c = 3;
	t_list *lst = ft_lstnew(&a);
	ft_lstadd_back(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));

	ft_lstiter(lst, increment_content);

	assert(a == 2 && b == 3 && c == 4);
	print_list(lst); // prints addresses, could print values if you cast
	printf("ft_lstiter incremented all values.\n");

	ft_lstclear(&lst, NULL);
	printf("\n");
}

/* ---------------- ft_lstmap ---------------- */
static void RunLstMapTest(void)
{
	printf("=== Testing ft_lstmap ===\n");
	int a = 1, b = 2, c = 3;
	t_list *lst = ft_lstnew(&a);
	ft_lstadd_back(&lst, ft_lstnew(&b));
	ft_lstadd_back(&lst, ft_lstnew(&c));

	t_list *mapped = ft_lstmap(lst, duplicate_content, del_int);

	int *val1 = (int*)mapped->content;
	int *val2 = (int*)mapped->next->content;
	int *val3 = (int*)mapped->next->next->content;

	assert(*val1 == 2 && *val2 == 4 && *val3 == 6);
	printf("ft_lstmap doubled the values: %d, %d, %d\n", *val1, *val2, *val3);

	ft_lstclear(&lst, NULL);
	ft_lstclear(&mapped, del_int);
	printf("\n");
}

/* ---------------- Main ---------------- */
int main(void)
{
	RunLstNewTest();
	RunLstAddFrontAndSizeTest();
	RunLstLastTest();
	RunLstAddBackTest();
	RunLstDelOneTest();
	RunLstClearTest();
	RunLstIterTest();
	RunLstMapTest();

	printf("All linked list tests passed!\n");
	return 0;
}
