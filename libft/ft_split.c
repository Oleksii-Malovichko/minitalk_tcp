/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:31:27 by omalovic          #+#    #+#             */
/*   Updated: 2024/10/21 16:16:28 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

int	get_word_length(const char **s, char c)
{
	int	length;

	length = 0;
	while (**s != c && **s && length++ >= 0)
		(*s)++;
	return (length);
}

char	*get_next_word(const char **s, char c)
{
	const char	*start;
	char		*word;
	int			length;
	int			i;

	i = 0;
	while (**s == c && **s)
		(*s)++;
	if (**s == '\0')
		return (NULL);
	start = *s;
	length = get_word_length(s, c);
	word = (char *)malloc(length + 1);
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

char	**clean_all(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		index;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (*s && word_count--)
	{
		result[index] = get_next_word(&s, c);
		if (!result[index])
			return (clean_all(result));
		index++;
	}
	result[index] = NULL;
	return (result);
}

/* int main() {
    const char *str = "xxxxxxxxhello!zzzzzzz";
    char delimiter = 'z';
    char **result = ft_split(str, delimiter);
	if (result) {
        int i = 0;
        while (result[i] != NULL) {
            printf("%s\n", result[i]);
            i++;
        }
    }
} */