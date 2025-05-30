/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:17:02 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/30 09:17:45 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/**
 * Count the number of words in the string, separated by space, tab, or new line
 */
int	count_word(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i])
	{
		// Skipping separators
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;

		// If a non-null char is found, it's the start of a word
		if (str[i] != '\0')
			count++;

		// Skip the word until we reach the next separator or null terminator
		while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'))
			i++;
	}
	return (count);
}

/**
 * Copy the characters from str[start] to str[end-1] into tab[]
 */
void	copy_words(char *tab, char *str, int start, int end)
{
	int	i = 0;

	while (start < end)
		tab[i++] = str[start++];
	tab[i] = '\0';
}

/**
 * Find the next word in the string by updating start and end indices
 * Return 1 if a word was found, 0 otherwise
 */

 int	find_next_word(char *str, int *start, int *end)
 {
	int i = *end;

	// Skip separators to find the start of the next word
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	*start = i;

	// Move to the end of the word
	while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'))
		i++;
	*end = i;

	return (*start < *end);
 }

 /**
  * Allocates and fills the array of word strings
  * Return 1 on success, 0 on failure (and frees already allocated memory)
  */

  int	ft_fill_words(char **tab, char *str)
  {
	int	start = 0;
	int	end = 0;
	int	word = 0;

	// Find and copy each word
	while (find_next_word(str, &start, &end))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (!tab[word])
		{
			while (word > 0)
				free(tab[word--]);
			free(tab);
			return (0);
		}
		copy_words(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
  }

  /**
   * Main function: Splits the string into a NULL-terminated array of strings
   *
   */
char	**ft_split(char *str)
{
	char	**result;
	int		size;

	size = count_word(str); // Count how many words in the string, for malloc allocation
	result =  malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	if (!ft_fill_words(result, str))
	{
		free(result);
		return (NULL);
	}
	return (result);
}
