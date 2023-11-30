/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_revrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:06:25 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/18 01:41:04 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*revrotate_a(t_list *stack)
{
	t_list	*last;
	int		cont;

	cont = stack->count;
	last = stack;
	while (last->next->next)
		last = last->next;
	last->next->next = stack;
	stack = last->next;
	last->next = NULL;
	stack->count = cont;
	write (1, "rra\n", 4);
	return (stack);
}

t_list	*revrotate_b(t_list *stack)
{
	t_list	*last;
	int		cont;

	cont = stack->count;
	last = stack;
	while (last->next->next)
		last = last->next;
	last->next->next = stack;
	stack = last->next;
	last->next = NULL;
	stack->count = cont;
	write (1, "rrb\n", 4);
	return (stack);
}

void	revrotate_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		cont;

	cont = (*stack_a)->count;
	last = *stack_a;
	while (last->next->next)
		last = last->next;
	last->next->next = *stack_a;
	*stack_a = last->next;
	last->next = NULL;
	(*stack_a)->count = cont;
	cont = (*stack_b)->count;
	last = *stack_b;
	while (last->next->next)
		last = last->next;
	last->next->next = *stack_b;
	*stack_b = last->next;
	last->next = NULL;
	(*stack_b)->count = cont;
	write (1, "rrr\n", 4);
}
