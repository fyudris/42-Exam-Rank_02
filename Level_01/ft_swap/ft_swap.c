/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:12:54 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 17:18:18 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_swap(int *a, int *b)
{
	if (!a || !b)
		return ;
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*
#include <stdio.h>

int	main()
{
	int a = 99;
	int b = 42;

	printf("Before: a = %i, b = %i\n", a, b);
	ft_swap(&a, &b);
	printf("After: a = %i, b = %i\n", a, b);
	return (0);
}
*/
