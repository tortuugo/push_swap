/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:22:32 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 16:25:53 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	valid_sol(t_list *stack, t_list *stack_b)
{
	if (!stack || !stack->next)
	{
		if (!stack_b)
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
		return ;
	}
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			write (1, "KO\n", 3);
			return ;
		}
		stack = stack->next;
	}
	if (!stack_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	move_reader(t_list **stack, t_list **stack_b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			return (1);
		if (check_move(stack, stack_b, move) == 0)
		{
			write (2, "Error\n", 6);
			free (move);
			return (0);
		}
		free (move);
	}
	return (1);
}
