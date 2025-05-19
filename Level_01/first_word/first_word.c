/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:29:20 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/19 22:48:33 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	// Check for number of argument
	if (argc == 2)
	{
		unsigned int	i;
		i = 0;
		// Loop over possible spaces (32) and tab (9)
		while (argv[1][i] && (argv[1][i] == 32 || argv[1][i] == 9))
			i++;
		// Start printing until we find either a space, tab, or \0
		while (argv[1][i] && (argv[1][i] != 32 && argv[1][i] != 9))
			write(1, &argv[1][i++], 1);
	}
	// Write \n at the end for both correct & error case
	write(1, "\n", 1);
	return (0);
}
