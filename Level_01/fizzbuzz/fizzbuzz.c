/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:32 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 16:20:00 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main()
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i%3 == 0 && i%5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i%3 == 0)
			write(1, "fizz", 4);
		else if (i%5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
