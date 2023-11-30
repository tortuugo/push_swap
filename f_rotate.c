/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:28:20 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/18 01:42:02 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate_a(t_list *stack)
{
	t_list	*i;
	int		cont;

	cont = stack->count;
	i = stack;
	while (i->next)
		i = i->next;
	i->next = stack;
	stack = stack->next;
	i->next->next = NULL;
	write (1, "ra\n", 3);
	stack->count = cont;
	return (stack);
}

t_list	*rotate_b(t_list *stack)
{
	t_list	*i;
	int		cont;

	cont = stack->count;
	i = stack;
	while (i->next)
		i = i->next;
	i->next = stack;
	stack = stack->next;
	i->next->next = NULL;
	write (1, "rb\n", 3);
	stack->count = cont;
	return (stack);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	int		cont;

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
	write (1, "rr\n", 3);
}
