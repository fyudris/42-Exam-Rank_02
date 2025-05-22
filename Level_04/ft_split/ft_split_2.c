#include <unistd.h>
#include <stdlib.h>


/**
 * Count the number of words in a str
 *
 */
int	count_words(char *str)
{
	int	count = 0;
	int	i = 0;

	while (str[i])
	{
		// Skipping all separators
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		// If a non-null char is found, it's the start of a word
		if (str[i])
			count++;
		// Skip the word until we reach the next separator or null terminator
		while (str[i] && (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'))
			i++;
	}
	return (count);
}

/**
 * Find the next word in the string by updating start and end indexes
 * @return 1 if a word found, 0 otherwise
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
 * Allocates and fill the array of word strings
 * @return 1 on success, 0 on failuer (and frees already allocated memory)
 */
int	ft_fill_words(char **result, char *str)
{
	int	start_idx = 0;
	int	end_idx = 0;
	int	word = 0;

	// Find the next word and copy to result
	// The start and end index will be updated according to the position
	// of the next word
	while (find_next_word(str, &start_idx, &end_idx))
	{
		// Allocate memory for each word in the result array
		result[word] = malloc((end_idx - start_idx + 1) * sizeof(char));
		if (!result[word])
		{
			while (word > 0)
				free(result[word--]);
			free(word);
			return (0);
		}
		// Memory allocation successful, start copying words
		int i = 0;
		while (start_idx < end_idx)
			result[i++] = str[start_idx++];
		result[i] = '\0';
		word++;
	}
	result[word] = NULL;
	return (1);
}


/**
 * Main function: Splits the string into NUll-terminated array of strings
 */
char	**ft_split(char *str)
{
	char	**result;
	int		size;

	// Count the number of words in str for malloc allocation
	size = count_words(str);
	result = malloc (sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);

	// Try to fill result with words, if fail, free everything
	// Otherwise return the result
	if (!ft_fill_words(result, str))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

