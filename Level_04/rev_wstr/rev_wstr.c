/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:40:02 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 03:49:01 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int first_word;

	i = 0;
	first_word = 0;

	if (ac == 2)
	{
		// Step 1: Find end of string
		while (av[1][i] != '\0')
			i++;
		i--; // Move to last character (not null terminator)

		while (i >= 0)
		{
			// Step2: Skip trailing spaces/tabs
			while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
				i--;

			// Step 3: Mark end of the word
			j = i;

			// Step 4: Move back to the start of the word
			while (j >= 0 && av[1][j] != ' ' && av[1][j] != '\t')
				j--;

			// Step 5: Print space before word if it's not the first
			if (first_word)
				write(1, " ", 1);
			// Step 6: Print the word
			write(1, &av[1][j + 1], i - j);
			first_word = 1;
			i = j; // move to character before this word
		}
	}
	write(1, "\n", 1);
	return (0);
}
