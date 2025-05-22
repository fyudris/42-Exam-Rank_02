/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 04:11:16 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 04:11:18 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i, j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1; // Start one step ahead to avoid comparing tab[i] to itself
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				// Swap tab[i] and tab[j]
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
