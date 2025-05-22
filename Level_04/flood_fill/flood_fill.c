/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:48:35 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 00:59:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	// Check if current already filled or does not match the target character
	if (tab[row][col] == 'F' || tab[row][col] != target)
		return ;
	// Otherwise, mark current cell as filled
	tab[row][col] = 'F';

	// Recursively fill neighboring cells
	fill(tab, size, target, row - 1, col); // Fill cell above
	fill(tab, size, target, row + 1, col); // Fill cell below
	fill(tab, size, target, row, col - 1); // Fill cell left
	fill(tab, size, target, row, col + 1); // Fill cell right


}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.y, begin.x);
}
