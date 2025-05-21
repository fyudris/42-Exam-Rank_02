/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:29:20 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 16:02:15 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	//Check for the number of arguments
	if (argc == 2)
	{
		unsigned int	i;

		i = 0;
		//Skip tabs and spaces before the first word
		while (argv[1][i] == 9 || argv[1][i] == 32)
			i++;
		while (argv[1][i] && (argv[1][i] != 9 && argv[1][i] != 32))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
