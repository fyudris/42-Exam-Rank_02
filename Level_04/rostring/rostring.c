/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:59:55 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/30 10:13:02 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int ft_putchar(int c)
{
	return(write(1, &c, 1));
}

int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}

	int i = 0;
	int start_firstword = 0;
	char *str = av[1];

	//skips leadig spaces
	while (str[i] && is_space(str[i]))
		i++;
	start_firstword = i;

	// skip first word
	while (str[i] && !is_space(str[i]))
		i++;

	while(str[i])
	{
		while (str[i] && is_space(str[i]))
		{
			i++;
		}

		if (str[i] && !is_space(str[i]))
			ft_putchar(' ');

		while (str[i] && !is_space(str[i]))
		{
			ft_putchar(str[i]);
			i++;
		}
		// i++;
	}

	// print first word
	ft_putchar(' ');
	while (str[start_firstword] && !is_space(str[start_firstword]))
	{
		ft_putchar(str[start_firstword]);
		start_firstword++;
	}
	ft_putchar('\n');
	return (0);
}
