/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:01:46 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/12 16:42:40 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_a(t_list *stack, t_list *n_stack)
{
	int	n;

	if (!stack || !n_stack)
		return (NULL);
	n_stack->count = stack->count;
	n = stack->content;
	stack->content = n_stack->content;
	n_stack->content = n;
	write (1, "sa\n", 3);
	return (stack);
}

t_list	*swap_b(t_list *stack, t_list *n_stack)
{
	int	n;

	if (!stack || !n_stack)
		return (NULL);
	n_stack->count = stack->count;
	n = stack->content;
	stack->content = n_stack->content;
	n_stack->content = n;
	write (1, "sb\n", 3);
	return (stack);
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	int	n;

	if (!(*stack_a) || !(*stack_b)
		|| !((*stack_a)->next) || !((*stack_b)->next))
		return ;
	(*stack_a)->next->count = (*stack_a)->count;
	n = (*stack_a)->content;
	(*stack_a)->content = ((*stack_a)->next)->content;
	((*stack_a)->next)->content = n;
	(*stack_b)->next->count = (*stack_b)->count;
	n = (*stack_b)->content;
	(*stack_b)->content = ((*stack_b)->next)->content;
	((*stack_b)->next)->content = n;
	write (1, "ss\n", 3);
}
