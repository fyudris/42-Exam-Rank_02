/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:46 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 17:09:57 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

#include <stdio.h>

int	main()
{
	printf("Len = %i\n", ft_strlen("HELLO WORLD\n"));
	printf("Len = %i\n", ft_strlen(""));
	return (0);
}
