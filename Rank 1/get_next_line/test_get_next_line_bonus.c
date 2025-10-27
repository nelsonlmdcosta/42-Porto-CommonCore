/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:41:03 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/27 13:02:24 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

void Test_RegularFile(void)
{
	int fd;
	char *line;

	fd = open("../test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening test1.txt");
		return ;
	}
	printf("=== Test: Regular file ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("FD1: %s", line);
		free(line);
	}
	close(fd);
	printf("=== End of test1.txt ===\n\n");
}

void Test_EmptyFile(void)
{
	int fd;
	char *line;

	fd = open("../empty.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening empty.txt");
		return ;
	}
	printf("=== Test: Empty file ===\n");
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
}

void Test_FileNoNewLine(void)
{
	int fd;
	char *line;

	fd = open("../no_newline.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening no_newline.txt");
		return ;
	}
	printf("=== Test: File with no newline at EOF ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("FD3: %s", line);
		free(line);
	}
	close(fd);
	printf("=== End of no_newline.txt ===\n\n");
}

void Test_LongLine(void)
{
	int fd;
	char *line;

	fd = open("../long_line.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening long_line.txt");
		return ;
	}
	printf("=== Test: File with very long line ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("FD_LONG: %s\n", line);
		free(line);
	}
	close(fd);
	printf("=== End of long_line.txt ===\n\n");
}

void Test_Stdin(void)
{
	char *line;
	printf("=== Test: Standard input (stdin) ===\n");
	printf("Type a few lines (Ctrl+D to end):\n");
	while ((line = get_next_line(0)) != NULL)
	{
		printf("STDIN: %s", line);
		free(line);
	}
	printf("=== End of stdin ===\n\n");
}

void Test_MultipleFDs(void)
{
	int fd1, fd2, fd3;
	char *line1, *line2, *line3;

	fd1 = open("../test1.txt", O_RDONLY);
	fd2 = open("../test2.txt", O_RDONLY);
	fd3 = open("../no_newline.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Error opening test files");
		return;
	}

	printf("=== Test: Multiple file descriptors interleaved ===\n");

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if (!line1 && !line2 && !line3)
			break ;

		if (line1)
		{
			printf("FD1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("FD2: %s", line2);
			free(line2);
		}
		if (line3)
		{
			printf("FD3: %s", line3);
			free(line3);
		}
	}

	close(fd1);
	close(fd2);
	close(fd3);
	printf("=== End of multiple FD test ===\n\n");
}

void Test_MixedFD_Stdin(void)
{
	int fd;
	char *line;

	fd = open("../test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening test1.txt");
		return ;
	}

	printf("=== Test: Interleaving FD and stdin ===\n");
	printf("Type a line for stdin (Ctrl+D to end):\n");

	for (int i = 0; i < 3; ++i)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("FD1: %s", line);
			free(line);
		}

		line = get_next_line(0); // stdin
		if (line)
		{
			printf("STDIN: %s", line);
			free(line);
		}
	}

	close(fd);
	printf("=== End of interleaved FD/stdin test ===\n\n");
}

int main(void)
{
	Test_RegularFile();
	Test_EmptyFile();
	Test_FileNoNewLine();
	Test_LongLine();
	//Test_Stdin();
	Test_MultipleFDs();
	//Test_MixedFD_Stdin();

	return 0;
}
