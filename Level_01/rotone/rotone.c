/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:45 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 20:26:52 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		unsigned int	i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 65 && av[1][i] <= 90)
			{
				if (av[1][i] == 90)
					av[1][i] = 65;
				else
					av[1][i] += 1;
			}
			else if (av[1][i] >= 97 && av[1][i] <= 122)
                	{
                        	if (av[1][i] == 122)
                                	av[1][i] = 97;
				else
					av[1][i] += 1;
                	}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
