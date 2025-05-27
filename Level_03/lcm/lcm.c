/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 04:02:35 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 04:11:54 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned	int lcm(unsigned int a, unsigned int b)
{
	// Look for max value of a and b as starting point
	unsigned int g = (a > b) ? a : b;

	// Check for zeros
	if (a == 0 || b == 0)
		return (0);

	// Brute force
	while (1)
	{
		if ((g % a == 0) && (g % b) == 0)
		g++;
	}
}

/**
 * Variation using GCD / HCD
 */
unsigned	int gcd(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned	int lcm_euclid(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / gcd(a, b)) * b);

}
