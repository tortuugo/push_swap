/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:04:43 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/20 20:56:57 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_list **stack)
{
	t_list	*i;
	int		pos;

	pos = 0;
	i = *stack;
	while (i)
	{
		i->pos = pos;
		if (pos > ((*stack)->count / 2))
			i->cost = (*stack)->count - pos;
		else
			i->cost = pos;
		pos++;
		i = i->next;
	}
}

int	rrr_cost(t_list *a, t_list *b, int cont)
{
	int	sol;

	sol = a->cost + a->true_pos->cost;
	if (a->pos <= cont && a->true_pos->pos <= (b->count / 2))
	{
		if (a->cost <= a->true_pos->cost)
			sol = a->true_pos->cost;
		else
			sol = a->cost;
	}
	else if (a->pos > cont && a->true_pos->pos > (b->count / 2))
	{
		if (a->cost <= a->true_pos->cost)
			sol = a->true_pos->cost;
		else
			sol = a->cost;
	}
	return (sol);
}

t_list	*lower_cost(t_list *stack, t_list *stack_b)
{
	t_list	*sol;
	int		total_cost;
	int		aux_cost;
	int		cont;

	cont = stack->count / 2;
	sol = stack;
	total_cost = stack->cost + stack->true_pos->cost;
	while (stack)
	{
		aux_cost = rrr_cost(stack, stack_b, cont);
		if (aux_cost < total_cost)
		{
			total_cost = aux_cost;
			sol = stack;
		}
		stack = stack->next;
	}
	return (sol);
}
