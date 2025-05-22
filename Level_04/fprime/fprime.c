/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:14:42 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 02:22:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"

int	main(int ac, char **av)
{
	int	i = 2; // Start deviding from 2
	int	num;

	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 1)
			write(1, "1", 1); // Special case: 1 has no prime number

		while (i <= num) // Loop until number is fully factorized
		{
			if (num % i == 0) // If i devides num without rest, it's a factor
			{
				write(1, &i, 1);
				num = num / i;
				if (num != 1) // There's still more factors remain
					write(1, "*", 1);
			}
			else
				i++; // Moves to the next candidate factor
		}
	}
	write(1, "\n", 1);
	return (0);
}
