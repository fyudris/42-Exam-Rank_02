/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:24:18 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 21:41:50 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_whitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32 ? 1 : 0);
}

int	ft_is_digit(int c)
{
	return (c >= 48 && c <= 57 ? 1 : 0);
}


int     ft_atoi(const char *str)
{
	int	result = 0;
	int	sign = 1;
	int	i = 0;

	// Skip the spaces
	while (ft_is_whitespace(str[i]))
		i++;
	// Check for sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	printf("Result = %d\n", ft_atoi("16386"));
	printf("Result = %d\n", ft_atoi("     16386   "));
	printf("Result = %d\n", ft_atoi("    +16386"));
	printf("Result = %d\n", ft_atoi("       -16386"));
	printf("Result = %d\n", ft_atoi("16386    "));
	printf("Result atoi = %d\n", atoi(""));
	printf("Result = %d\n", ft_atoi("0"));
	printf("Result = %d\n", ft_atoi("-0"));
	return (0);
}
