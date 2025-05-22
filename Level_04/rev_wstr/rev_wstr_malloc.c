/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:50:51 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 04:01:33 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * Print a string
 */

 void	put_str(char *str)
 {
	while (*str)
		write(1, str++, 1);
 }

 /**
  * Count how many words are in the string
  * Words are sequences separated by spaces or tabs
  */
 int	count_words(char *str)
 {
	int	count = 0;

	while (*str)
	{
		// Skip any spaces or tabs
		while (*str == ' ' || *str == '\t')
			str++;
		// If any word starts, count it
		if (*str)
		{
			count++;
			// Move past this word
			while (*str && (*str != ' ' || *str != '\t'))
				str++;
		}
	}
	return (count);
 }

 /**
  * Allocate memory and copy a word from the string
  */
char	*extract_word(char *start, int len)
{
	char	*word = (char *) malloc(len + 1);
	if (!word)
		return (NULL);
	int i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

/**
 * Split the string into an array of words
 */

 char **split_words(char *str, int word_count)
{
	// Allocate memory for the array of word pointers (+1 for NULL at the end)
	char **words = (char **)malloc(sizeof(char *) * (word_count + 1));
	int i = 0;        // Index for words array
	char *start;      // Pointer to the start of each word
	int len;          // Length of the current word

	if (!words)
		return NULL;

	// Traverse the entire input string
	while (*str)
	{
		// Step 1: Skip any spaces or tabs to find the beginning of a word
		while (*str == ' ' || *str == '\t')
			str++;

		// Step 2: If we're not at the end, we found a word
		if (*str)
		{
			start = str; // Mark the start of the word
			len = 0;

			// Step 3: Count characters until the end of the word
			// (i.e., until a space, tab, or null terminator)
			while (*str && *str != ' ' && *str != '\t')
			{
				len++;
				str++;
			}

			// Step 4: Allocate memory and copy the word into the array
			// extract_word creates a new null-terminated string
			words[i++] = extract_word(start, len);
		}
	}

	// Step 5: Null-terminate the array of strings
	words[i] = NULL;

	return words;
}

 // Free the memory for the array of words
void free_words(char **words)
{
	int i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		// Step 1: Count words in input
		int word_count = count_words(av[1]);

		// Step 2: Split string into words
		char **words = split_words(av[1], word_count);

		// Step 3: Print words in reverse order
		if (words)
		{
			for (int i = word_count - 1; i >= 0; i--)
			{
				put_str(words[i]);
				if (i > 0)
					write(1, " ", 1); // Add space between words
			}
			free_words(words); // Step 4: Free memory
		}
	}
	write(1, "\n", 1); // Always end with newline
	return 0;
}
