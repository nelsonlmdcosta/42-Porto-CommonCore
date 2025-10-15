/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluis-mo <nluis-mo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:13:44 by nluis-mo          #+#    #+#             */
/*   Updated: 2025/10/15 22:05:42 by nluis-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *string, char seperator)
{
	size_t	count;
	int		inside_word;

	count = 0;
	inside_word = 0;
	while (*string != '\0')
	{
		if (*string != seperator && !inside_word)
		{
			inside_word = 1;
			count++;
		}
		else if (*string == seperator)
		{
			inside_word = 0;
		}
		string++;
	}
	return (count);
}

static char	*chop_and_duplicate(const char *s, size_t len)
{
	size_t	i;
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memset(word, 0, len + 1);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	extract_words(char **output, const char *string, char seperator)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*string)
	{
		if (*string != seperator)
		{
			len = 0;
			while (string[len] && string[len] != seperator)
				len++;
			output[i] = chop_and_duplicate(string, len);
			if (output[i] == NULL)
				return (0);
			i++;
			string += len;
			continue ;
		}
		string++;
	}
	output[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	total_words;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	output = malloc(sizeof(char *) * (total_words + 1));
	if (!output)
		return (NULL);
	ft_memset(output, 0, sizeof(char *) * (total_words + 1));
	if (!extract_words(output, s, c))
	{
		free_all(output);
	}
	return (output);
}
