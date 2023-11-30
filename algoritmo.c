/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:48 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/20 19:20:02 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*sol;

	sol = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->content > sol->content)
			sol = stack;
		stack = stack->next;
	}
	return (sol);
}

void	set_true_stack(t_list **stack_a, t_list *stack_b)
{
	t_list		*i;
	t_list		*j;
	long int	max;

	i = *stack_a;
	while (i)
	{
		j = stack_b;
		max = LONG_MIN;
		while (j)
		{
			if (max < j->content && j->content < i->content)
			{
				i->true_pos = j;
				max = j->content;
			}
			j = j->next;
		}
		if (max == LONG_MIN)
			i->true_pos = find_max(stack_b);
		i = i->next;
	}
}

void	finish_rotate(t_list *move, t_list **stack_a, t_list **stack_b)
{
	while (move != *stack_a && move->pos <= (*stack_a)->count / 2)
		*stack_a = rotate_a(*stack_a);
	while (move != *stack_a && move->pos > (*stack_a)->count / 2)
		*stack_a = revrotate_a(*stack_a);
	while (move->true_pos != *stack_b
		&& move->true_pos->pos <= (*stack_b)->count / 2)
		*stack_b = rotate_b(*stack_b);
	while (move->true_pos != *stack_b
		&& move->true_pos->pos > (*stack_b)->count / 2)
		*stack_b = revrotate_b(*stack_b);
}

void	decision(t_list **stack_a, t_list **stack_b)
{
	t_list	*move;

	move = lower_cost(*stack_a, *stack_b);
	while (move->pos <= (*stack_a)->count / 2
		&& move->true_pos->pos <= (*stack_b)->count / 2
		&& move != *stack_a
		&& move->true_pos != *stack_b)
	{
		rotate_rr(stack_a, stack_b);
		set_cost(stack_a);
		set_cost(stack_b);
		set_true_stack(stack_a, *stack_b);
	}
	while (move->pos > (*stack_a)->count / 2
		&& move->true_pos->pos > (*stack_b)->count / 2
		&& move != *stack_a
		&& move != *stack_b)
	{
		revrotate_rr(stack_a, stack_b);
		set_cost(stack_a);
		set_cost(stack_b);
		set_true_stack(stack_a, *stack_b);
	}
	finish_rotate(move, stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	init_do(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
	{
		push_b(stack_a, stack_b);
		if ((*stack_a)->count > 3)
			push_b(stack_a, stack_b);
	}
	while ((*stack_a)->count != 3)
	{
		set_cost(stack_a);
		set_cost(stack_b);
		set_true_stack(stack_a, *stack_b);
		decision(stack_a, stack_b);
	}
	check_stack_b(stack_b);
	*stack_a = last_three(*stack_a);
	final_sort(stack_a, stack_b);
}
