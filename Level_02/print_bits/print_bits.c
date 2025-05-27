/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:22:53 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 00:28:24 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Function takes 1 byte = 8 bits

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char bit = 0;

	while (i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}


int	main()
{
	print_bits(255);
	return (0);
}
