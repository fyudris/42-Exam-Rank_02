/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:19:45 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/24 15:59:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int	a = atoi(av[1]);
		char	op = av[2][0];
		int	b = atoi(av[3]);
		//printf("a = %d, op = %c, b = %d\n", a, op, b);

		if (op == '+')
			printf("%d", a + b);
		else if (op == '-')
			printf("%d", a - b);
		else if (op == '*')
			printf("%d", a * b);
		else if (op == '/')
			printf("%d", a / b);
		else if (op == '%')
			printf("%d", a % b);
	}
	printf("\n");
	return (0);
}
