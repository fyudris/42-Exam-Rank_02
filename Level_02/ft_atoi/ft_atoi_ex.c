/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:09:16 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/24 17:27:10 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}

	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

#include <stdio.h>
#include <stdlib.h>

int     main()
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

