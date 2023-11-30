/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:01:46 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 15:41:38 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

t_list	*swap_a_bonus(t_list *stack)
{
	int	n;

	if (!stack || !(stack->next))
		return (NULL);
	stack->next->count = stack->count;
	n = stack->content;
	stack->content = stack->next->content;
	stack->next->content = n;
	return (stack);
}

t_list	*swap_b_bonus(t_list *stack)
{
	int	n;

	if (!stack || !(stack->next))
		return (NULL);
	stack->next->count = stack->count;
	n = stack->content;
	stack->content = stack->next->content;
	stack->next->content = n;
	return (stack);
}

void	swap_ss_bonus(t_list **stack_a, t_list **stack_b)
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
}
