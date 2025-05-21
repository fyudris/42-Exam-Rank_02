/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:43:52 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 21:53:21 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	// Loop over if we still have char left or if the char in s1 == s2
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

#include <string.h>
#include <stdio.h>

int	main()
{
	printf("Result ft_strcmp = %d\n", ft_strcmp("", ""));
	printf("Result strcmp = %d\n", strcmp("", ""));
	
	printf("Result ft_strcmp = %d\n", ft_strcmp("ABC", "ABC"));
	printf("Result strcmp = %d\n", strcmp("", ""));
	
	printf("Result ft_strcmp = %d\n", ft_strcmp("ABC", "AB"));
	printf("Result strcmp = %d\n", strcmp("ABC", "AB"));
	
	printf("Result ft_strcmp = %d\n", ft_strcmp("ABA", "ABZ"));
	printf("Result strcmp = %d\n", strcmp("ABA", "ABZ"));
	
	printf("Result ft_strcmp = %d\n", ft_strcmp("ABJ", "ABC"));
	printf("Result strcmp = %d\n", strcmp("ABJ", "ABC"));
	
	printf("Result ft_strcmp = %d\n", ft_strcmp("\201", "A"));
	printf("Result strcmp = %d\n", strcmp("\201", "A"));
	return (0);
}
