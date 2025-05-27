/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 03:13:29 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 03:20:12 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 0;

	// Skips initial spaces
	while (is_space(av[1][i]))
		i++;

	while (av[1][i])
	{
		// If a space is found, check for following spaces and skip over
		if (is_space(av[1][i]))
		{
			while (is_space(av[1][i]))
				i++;
			//If there's moret text after the space, write one space
			if (av[1][i])
				write(1, " ", 1);
		}
		else
		{
			// If a non-space char is found, we write it down
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
