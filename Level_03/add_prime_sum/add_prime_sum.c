/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:45:54 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 03:06:38 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int	is_prime(int n)
{
	if (n < 2)
		return (0);
	int i = 2;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	char digit = (n % 10) + '0';
	write (1, &digit, 1);
}

int	ft_atoi(char *str)
{
	int	result = 0;
	int i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}


int	main(int ac, char **av)
{
	int sum = 0;
	if (ac == 2)
	{
		int n = ft_atoi(av[1]);
		if (n <= 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		int i = 0;
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
	}
	ft_putnbr(sum);
	write(1, "\n", 0);
	return (0);
}
