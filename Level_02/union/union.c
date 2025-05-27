/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:27:00 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 02:38:41 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	lookup[256] = {0};

	if (ac == 3)
	{
		// Go through each char in input and mark it as seen in lookup table
		while (av[1][i])
			lookup[(unsigned char)av[1][i++]] = 1;
		i = 0;
		while (av[2][i])
			lookup[(unsigned char)av[2][i++]] = 1;

		// Print first string's unique char in order
		i = 0;
		while (av[1][i])
		{
			if (lookup[(unsigned char)av[1][i]])
			{
				write(1, &av[1][i], 1);
				lookup[(unsigned char)av[1][i]] = 0;
			}
			i++;
		}


		// Print second string's unique char in order
		i = 0;
		while (av[2][i])
		{
			if (lookup[(unsigned char)av[2][i]])
			{
				write(1, &av[2][i], 1);
				lookup[(unsigned char)av[2][i]] = 0;
			}
			i++;
		}


	}
	write(1, "\n", 1);
	return (0);
}
