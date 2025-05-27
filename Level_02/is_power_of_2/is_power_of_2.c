/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:39:08 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 00:45:32 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    is_power_of_2(unsigned int n)
{
	return ((n > 0) && ((n & (n - 1)) == 0));
}
/*
#include <stdio.h>

int	main()
{
	printf("%d is power of 2 = %d\n", 0, is_power_of_2(0));
	printf("%d is power of 2 = %d\n", 144, is_power_of_2(144));
	printf("%d is power of 2 = %d\n", 32, is_power_of_2(32));
	printf("%d is power of 2 = %d\n", 256, is_power_of_2(256));
	printf("%d is power of 2 = %d\n", 100000, is_power_of_2(100000));

	return (0);
}
*/
