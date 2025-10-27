/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:32:31 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/27 16:37:00 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*
 * Note: According to POSIX, OPEN_MAX is the maximum number of files a process
 *       can have open simultaneously. However, on many Linux systems it is not
 *       defined (because the limit is runtime-variable), see:
 *         - POSIX specification for limits.h: OPEN_MAX defined only if fixed.
 *  https://pubs.opengroup.org/onlinepubs/009695399/basedefs/limits.h.html
 *         - GNU libc manual: OPEN_MAX if defined, else use
 *           sysconf(_SC_OPEN_MAX).
 *	https://sourceware.org/glibc/manual/latest/html_mono/libc.html
 *		#General-Limits
 *         - Linux bug discussion: OPEN_MAX macro removed/undefined in newer
 *           glibc.
 *  https://bugzilla.redhat.com/show_bug.cgi?id=21346
 *
 *	Most People won't care but as I work from Windows-CLion, I have to care :p
 *	So If Not Defined, We Do It Manually Here 1024 was the default I use
 *	originally But Felt Overkill So Dropped It
 */
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

int		has_newline(const char *s);
int		len_until_newline(const char *string);

#endif
