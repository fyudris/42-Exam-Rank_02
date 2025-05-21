/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:50:02 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/21 17:55:32 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	len = ft_strlen(argv[1]);

		while ((len - 1) >= 0)
		{
			write(1, &argv[1][len-1], 1);
			len--;
		}	

	}
	write(1, "\n", 1);
	return (0);
}
