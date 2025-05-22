/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:52:40 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 03:37:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	// Safety check: Check that pointer and node exist
	if (!begin_list || !*begin_list)
		return ;
	// If current node matches, remove it
	if (((int (*)(void *, void*))cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list; // Safe current node
		*begin_list = (*begin_list)->next; // Skip over current node
		free(tmp);
		ft_list_remove_if(begin_list, data_ref, cmp); // Recurse on the new head
	}
	else
	{
		// Move to the next node (pass address of the next pointer)
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
	}
}

#include <stdio.h>
#include <string.h>

int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

t_list	*create_node (char *data)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s -> ", (char *)head->data);
		head = head->next;
	}
	printf("NULLL\n");
}

void	free_list(t_list *head)
{
	t_list	*tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
int	main(void)
{
	// Build a list: apple -> banana -> apple -> cherry -> NULL
	t_list	*head = create_node("apple");
	head->next = create_node("banana");
	head->next->next = create_node("apple");
	head->next->next->next = create_node("cherry");

	printf("Original List: \n");
	print_list(head);

	// Remove all "apple" occurances
	ft_list_remove_if(&head, "apple", cmp_str);

	printf("\nResult List: \n");
	print_list(head);

	free_list(head);
	return (0);
}
