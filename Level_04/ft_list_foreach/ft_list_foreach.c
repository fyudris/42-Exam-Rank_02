/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:35:22 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 02:48:54 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list) // Tranverse through the list node by node
	{
		if (begin_list->data != NULL)
			// (*f)(begin_list->data); // Call the function on the current data
			f(begin_list->data);
		begin_list = begin_list->next; // Move to the next node
	}
}

#include <stdio.h>
void print_str(void *data)
{
	printf("%s\n", (char *)data);
}

int	main()
{
	t_list a = {NULL, "HELLO"};
	t_list b = {&a, "WORLD"};
	t_list c = {&b, "42"};

	ft_list_foreach(&c, print_str);
}
