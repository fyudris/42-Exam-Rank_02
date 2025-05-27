/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 03:37:40 by fyudris           #+#    #+#             */
/*   Updated: 2025/05/27 03:49:05 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_valid(int c, int base)
{
	char *lower_base = "0123456789abcdef";
	char *upper_base = "0123456789ABCDEF";
	int i = 0;

	while (i < base)
	{
		if (c == lower_base[i] || c == upper_base[i])
			return (1);
		i++;
	}
	return (0);
}

int	char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	res = 0;
	int	sign = 1;
	int digit;

	while (is_space(str[i]))
		i++;

	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] && is_valid(str[i], str_base))
	{
		digit = char_to_value(str[i]);
		res = res * str_base + digit;
		i++;
	}
	return (res * sign);
}
