/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 04:14:03 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 04:15:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

#include "list.h"

// Sorts a singly linked list in-place using the provided comparison function.
// Returns a pointer to the head of the sorted list.
t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *start;   // This will keep track of the head of the list
	int temp;        // Temporary variable for swapping data values
	int swapped;     // Flag to check if any swap occurred in a pass

	if (!lst)
		return (NULL); // If the list is empty, return NULL

	start = lst;     // Save the head of the list so we can always return it
	swapped = 1;     // Initialize swap flag to enter the while loop

	// Outer loop continues until a full pass is made with no swaps
	while (swapped)
	{
		swapped = 0;     // Reset swap flag at the beginning of each pass
		lst = start;     // Start from the beginning of the list

		// Traverse the list and compare adjacent elements
		while (lst->next)
		{
			// If elements are out of order according to cmp
			if (!cmp(lst->data, lst->next->data))
			{
				// Swap the data between the current and next node
				temp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = temp;

				swapped = 1; // Set flag to indicate a swap occurred
			}
			lst = lst->next; // Move to the next pair of nodes
		}
	}

	return (start); // Return the head of the sorted list
}
