/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:11:04 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/30 00:38:58 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	if (!lst)
		return (NULL);

	if (lst && !lst->next)
		return (lst);

	t_list	*current = lst;
	int swaped = 1;
	int temp;

	while (swaped)
	{
		swaped = 0;
		current = lst;
		while(current && current->next)
		{
			if ((*cmp)(current->data, current->next->data) == 0)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swaped = 1;
			}
			current = current->next;
		}
	}
	return (lst);
}
/**
int ascending(int a, int b)
{
	return (a <= b);
}

t_list *create_node(int num)
{
	t_list *newnode = (t_list *) malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->data = num;
	newnode->next = NULL;
	return (newnode);
}

void append_node(t_list **lst, t_list *newnode)
{
	if (!newnode)
		return ;
	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	t_list *current = *lst;
	while (current->next)
		current = current->next;
	current->next = newnode;
}

void print_list(t_list *lst)
{
	if (!lst)
		return ;
	t_list *current = lst;
	while (current && current->next)
	{
		printf("%d - ", current->data);
		current = current->next;
	}
	printf("%d ", current->data);
	printf("\n");
}

void	free_list(t_list *lst)
{
	t_list *current = lst;
	t_list *nextnode;

	while (current)
	{
		nextnode = current->next;
		free(current);
		current = nextnode;
	}
}

int	main()
{
	t_list *lst = NULL;
	append_node(&lst, create_node(5));
	append_node(&lst, create_node(2));
	append_node(&lst, create_node(4));
	append_node(&lst, create_node(1));
	append_node(&lst, create_node(3));
	append_node(&lst, create_node(2));

	printf("BEFORE: \n");
	print_list(lst);

	lst = sort_list(lst, ascending);
	printf("AFTER: \n");
	print_list(lst);

	free_list(lst);
	return (0);
}
*/
