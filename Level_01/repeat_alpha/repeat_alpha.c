/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:19:52 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 17:48:19 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned int	i = 0;
		char		*str = argv[1];
		unsigned int	rep;

		while (str[i])
		{
			rep = 1;
			if (str[i] >= 97 && str[i] <= 122)
				rep = str[i] - 96;
			if (str[i] >= 65 && str[i] <= 90)
				rep = str[i] - 64;
			unsigned int j = 0;
			while (j < rep)
			{
				write(1, &str[i], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
