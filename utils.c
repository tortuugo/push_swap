/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:52:42 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/20 19:02:20 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*only2(t_list *stack)
{
	if (stack->content > stack->next->content)
		stack = swap_a(stack, stack->next);
	return (stack);
}

t_list	*last_node(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_list	*last_three(t_list *stack_a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = stack_a->content;
	num2 = stack_a->next->content;
	num3 = stack_a->next->next->content;
	if (num3 < num2 && num1 < num3)
	{
		stack_a = revrotate_a(stack_a);
		stack_a = swap_a(stack_a, stack_a->next);
	}
	else if (num1 < num2 && num1 > num3)
		stack_a = revrotate_a(stack_a);
	else if (num1 > num2 && num1 < num3)
		stack_a = swap_a(stack_a, stack_a->next);
	else if (num2 < num1 && num2 > num3)
	{
		stack_a = swap_a(stack_a, stack_a->next);
		stack_a = revrotate_a(stack_a);
	}
	else if (num3 > num2 && num3 < num1)
		stack_a = rotate_a(stack_a);
	return (stack_a);
}

void	final_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*ult;
	int		min;

	min = (*stack_a)->content;
	while (*stack_b)
	{
		ult = last_node(*stack_a);
		if (min >= (*stack_a)->content && min > (*stack_b)->content)
			push_a(stack_a, stack_b);
		else if (ult->content > (*stack_b)->content)
			*stack_a = revrotate_a(*stack_a);
		else
			push_a(stack_a, stack_b);
	}
	while (ult->content < (*stack_a)->content)
	{
		*stack_a = revrotate_a(*stack_a);
		ult = last_node(*stack_a);
	}
}

void	check_stack_b(t_list **stack)
{
	t_list	*max;

	max = find_max(*stack);
	if (max == *stack)
		return ;
	while (max != *stack)
	{
		if (max->pos <= (*stack)->count / 2)
			*stack = rotate_b(*stack);
		else
			*stack = revrotate_b(*stack);
	}
}
