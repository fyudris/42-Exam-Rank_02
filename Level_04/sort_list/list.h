/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 04:15:07 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/22 04:15:09 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct      s_list
{
    int             data;           // The integer data stored in the node
    struct s_list   *next;          // Pointer to the next node in the list
}                   t_list;

#endif
