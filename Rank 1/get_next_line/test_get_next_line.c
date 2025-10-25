/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:52:13 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/25 15:00:34 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>      // for open()
#include <stdio.h>      // for printf()
#include <stdlib.h>     // for free()
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	// === Test 1: Regular file ===
	fd = open("../test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening test1.txt");
		return (1);
	}
	printf("=== Test 1: Reading test1.txt ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("LINE: %s", line);
		free(line);
	}
	close(fd);
	printf("=== End of test1.txt ===\n\n");

	// === Test 2: Empty file ===
	fd = open("../empty.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening empty.txt");
		return (1);
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

	// === Test 3: Standard input ===
	printf("=== Test 3: Reading from stdin ===\n");
	printf("Type something (Ctrl+D to end):\n");
	while ((line = get_next_line(0)) != NULL)
	{
		printf("STDIN LINE: %s", line);
		free(line);
	}
	printf("=== End of stdin ===\n\n");

	// === Test 4: Single line without newline at EOF ===
	fd = open("../no_newline.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening no_newline.txt");
		return (1);
	}
	printf("=== Test 4: Single line, no newline at EOF ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("LINE: %s", line);
		free(line);
	}
	close(fd);
	printf("=== End of no_newline.txt ===\n\n");

	return (0);
}
