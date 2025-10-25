/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:35:13 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/25 14:58:42 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	Reallocates a new string and returns the new pointer. This pointer copies
 *		Source Into It Then Copies The Characters We need From Additive buffer
 *
 *	Deallocates the old memory, and allocates new one with a size large enough
 *		To Hold The Old String + New String, It's Like A strlcpy with extra steps
 */
static char	*join_free(char *source, const char *additive, int copylength)
{
	int		sourcelength;
	char	*output;

	sourcelength = 0;
	if (source != NULL)
		sourcelength = ft_strlen(source);
	output = malloc(sourcelength + copylength + 1);
	if (!output)
		return (NULL);
	if (source)
	{
		ft_memmove(output, source, sourcelength);
		free(source);
	}
	ft_memmove(output + sourcelength, additive, copylength);
	output[sourcelength + copylength] = '\0';
	return (output);
}

/*
 * 	Shift Leftover Data To The Front, I Also Clean Out The Remaining Buffer
 * 		Not StrictlyNeeded Could Just Stick A Null Terminator
 * 		#DefensiveProgramming
 */
static void	shift_buffer(char *buffer)
{
	int	copyfromoffset;
	int	remainingspace;

	copyfromoffset = 0;
	while (buffer[copyfromoffset] && buffer[copyfromoffset] != '\n')
		copyfromoffset++;
	if (buffer[copyfromoffset] == '\n')
		copyfromoffset++;
	remainingspace = BUFFER_SIZE - copyfromoffset;
	ft_memmove(buffer, buffer + copyfromoffset, remainingspace);
	ft_memset(buffer + remainingspace, '\0', copyfromoffset);
}

/*
 * 	Fills The Buffer With Read Data, The Idea Is If There Is Data (That's Already
 * 		Been shifted We Want To Just Read What's Left Before Anything Else Is
 * 		Done
 *
 * 	If The Buffer Is Empty, Then We Just Go Ahead And Fill it With New Data
 * 		Returns 1 If it Has LeftOverData, 0/EOF on Finished Reading Or -1 For
 * 		Error (Read From ERRNO)
 *
 * 	Also Null Termiantes So It Acts As A String
 */
static int	fill_buffer(int fd, char *buffer)
{
	int	bytesread;

	if (buffer[0] != '\0')
		return (1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread <= 0)
		return (bytesread);
	buffer[bytesread] = '\0';
	return (bytesread);
}

/*
 * 	Appends the next chunk of the buffer into the output, return true if we hit
 * 		the end of the line, otherwise false so we can go through the wholr
 * 		process again! Ensures it returns a null terminated string regardless
 */
static int	append_chunk(char **output, char *buffer)
{
	int	chunk_len;

	chunk_len = len_until_newline(buffer);
	*output = join_free(*output, buffer, chunk_len);
	if (has_newline(buffer))
	{
		shift_buffer(buffer);
		return (1);
	}
	buffer[0] = '\0';
	return (0);
}

/*
 * 	Static variable to persist throughout the lifetime of the project, static
 * 		variables are guaranteed to be zero initialized (useful init?)
 *
 * 	We're going to use the current buffer if anything is inside, or read if
 * 		if it's empty, otherwise we break as we hit an error, once read we
 * 		call into append_chunk to retrieve a chunk of data out, of what is
 * 		hopefully the end of the line. If not we repeat till we hit the end
 * 		or find a full line.
 */
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*final_output;
	int			bytesread;
	int			newline_found;

	final_output = NULL;
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = fill_buffer(fd, buffer);
		if (bytesread <= 0)
			break ;
		newline_found = append_chunk(&final_output, buffer);
		if (newline_found)
			break ;
	}
	return (final_output);
}
