/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:16:36 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 15:20:54 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	long int	sol;
	int			neg;

	sol = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	if (!*str)
		return (LONG_MAX);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (LONG_MAX);
		sol = (sol + *str - '0') * 10;
		str++;
	}
	sol = (sol / 10) * neg;
	return (sol);
}
/*#include <stdlib.h>
int main(void)
{
	const char	str[] = "-13";
	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return (0);
}*/
