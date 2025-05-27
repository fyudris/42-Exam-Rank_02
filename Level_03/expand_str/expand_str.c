/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 03:22:59 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 03:29:16 by fyudris          ###   ########.fr       */
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
		write (1, "\n", 1);
		return (0);
	}
	int i = 0;

	//Skips all initial spaces
	while (is_space(av[1][i]))
		i++;

	while (av[1][i])
	{
		// If space is found, check further spaces and skip over
		if (is_space(av[1][i]))
		{
			while (is_space(av[1][i]))
				i++;
			// If a non-space char is found, print 3 spaces
			if (av[1][i])
				write (1, "   ", 3);
		}
		else
		{
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
