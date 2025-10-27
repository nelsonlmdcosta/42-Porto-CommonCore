/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:52:13 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/26 10:34:58 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void Test_RegularFile(void)
{
	int fd;
	char *line;

	// === Test 1: Regular file ===
	fd = open("../test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening test1.txt");
		return ;
	}
	printf("=== Test 1: Reading test1.txt ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("LINE: %s", line);
		free(line);
	}
	close(fd);
	printf("=== End of test1.txt ===\n\n");
}

void Test_EmptyFile(void)
{
	int fd;
	char *line;

	// === Test 2: Empty file ===
	fd = open("../empty.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening empty.txt");
		return ;
	}
	printf("=== Test 2: Reading empty.txt ===\n");
	line = get_next_line(fd);
	if (!line)
		printf("Correct: returned NULL for empty file\n");
	else
	{
		printf("Wrong: expected NULL, got '%s'\n", line);
		free(line);
	}
	close(fd);
	printf("=== End of empty.txt ===\n\n");
	fflush(stdout);
}

void Test_FileNoNewLine(void)
{
	int fd;
	char *line;

	// === Test 4: Single line without newline at EOF ===
	fd = open("../no_newline.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening no_newline.txt");
		return ;
	}
	printf("=== Test 4: Single line, no newline at EOF ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("LINE: %s", line);
		free(line);
	}
	close(fd);
	printf("=== End of no_newline.txt ===\n\n");
}

void Test_CIN(void)
{
	int fd = 0;
	char *line;

	// === Test 3: Standard input ===
	printf("=== Test 3: Reading from stdin ===\n");
	printf("Type something (Ctrl+D to end):\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("STDIN LINE: %s", line);
		free(line);
	}
	printf("=== End of stdin ===\n\n");
}

int main(void)
{
	Test_RegularFile();
	Test_EmptyFile();
	Test_FileNoNewLine();
	Test_CIN();

	return (0);
}