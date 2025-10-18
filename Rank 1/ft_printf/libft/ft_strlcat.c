/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:08:55 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/12 19:28:18 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This was bloody annoying to figure out exactly what was expected but here we
 * 		are, so following a page that is not the man to try get a better
 * 		understanding https://surl.li/sbrbyn // From Developer ARM strlcat
 * 		(ShortLink otherwise search for the comment after)
 *
 * Weird function, only writes to dst, if there is space, otherwise reports
 * 		the expected size of the concatenation
 *
 * Ties to compute the lengths of the buffers, without going past the copy size
 *
 * If by chance the size < destinations legnth then we exit early and let the
 * 		user know how much space we need
 *
 * Otherwise do the appending
 *
 * NOTE: That size is the size of the dst buffer, or the expected value of it
 * 		assuming the user input it correctly
 */
unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	src_index;

	dst_len = 0;
	src_len = 0;
	src_index = 0;
	while (dst_len < size && *(dst + dst_len) != '\0')
		dst_len++;
	while (*(src + src_len) != '\0')
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	while (*(src + src_index) != '\0' && (dst_len + src_index) < size - 1)
	{
		*(dst + dst_len + src_index) = *(src + src_index);
		src_index ++;
	}
	if (dst_len + src_index < size)
		*(dst + dst_len + src_index) = '\0';
	return (dst_len + src_len);
}
