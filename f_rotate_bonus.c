/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:28:20 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 16:03:38 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

t_list	*rotate_a_bonus(t_list *stack)
{
	t_list	*i;
	int		cont;

	if (!stack)
		return (stack);
	cont = stack->count;
	i = stack;
	while (i->next)
		i = i->next;
	i->next = stack;
	stack = stack->next;
	i->next->next = NULL;
	stack->count = cont;
	return (stack);
}

t_list	*rotate_b_bonus(t_list *stack)
{
	t_list	*i;
	int		cont;

	if (!stack)
		return (stack);
	cont = stack->count;
	i = stack;
	while (i->next)
		i = i->next;
	i->next = stack;
	stack = stack->next;
	i->next->next = NULL;
	stack->count = cont;
	return (stack);
}

void	rotate_rr_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	int		cont;

	if (!(*stack_a) || !(*stack_b))
		return ;
	cont = (*stack_a)->count;
	i = *stack_a;
	while (i->next)
		i = i->next;
	i->next = *stack_a;
	*stack_a = (*stack_a)->next;
	i->next->next = NULL;
	(*stack_a)->count = cont;
	i = *stack_b;
	cont = (*stack_b)->count;
	while (i->next)
		i = i->next;
	i->next = *stack_b;
	*stack_b = (*stack_b)->next;
	i->next->next = NULL;
	(*stack_b)->count = cont;
}
