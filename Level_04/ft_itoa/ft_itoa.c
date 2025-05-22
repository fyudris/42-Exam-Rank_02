/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:24:02 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 02:34:05 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Count the number of characters needed for the string
 */
int	ft_count_len(int nbr)
{
	int	len = 0;

	// If the number is zero or negative, we need at least one extra character f0r '0' (otherwise skipped by the while loop)  or '-'
	if (nbr <= 0)
		len++;

	// Count digits by deving by 10 repeatedly
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	long	num; // Safely handle INT_MIN
	char	*str;

	num = nbr;
	len = ft_count_len(num);
	str = (char *) malloc (sizeof(char) * (len + 1));

	if (!str)
		return (NULL);

	str[len] = '\0'; // Null terminate the string
	i = len - 1;

	// Handle negative number
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}

	// Extract digits from the end
	while (num > 9)
	{
		str[i] = (num % 10) + '0'; // Get last digit and convert to char
		num = num / 10; // Remove last digit
		i--;
	}
	str[i] = num + '0'; // Place the final (or only) digit
	
	return (str);
}
