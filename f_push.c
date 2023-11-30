/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:22:31 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/13 15:36:53 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int		n;
	int		cont_a;
	int		cont_b;
	t_list	*aux;

	cont_a = (*stack_a)->count;
	if (!(*stack_b))
		return ;
	cont_b = (*stack_b)->count;
	n = (*stack_b)->content;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	free (aux);
	aux = (t_list *) malloc(sizeof(t_list));
	if (!aux)
		return ;
	aux->content = n;
	aux->next = *stack_a;
	*stack_a = aux;
	write (1, "pa\n", 3);
	(*stack_a)->count = cont_a + 1;
	if (*stack_b)
		(*stack_b)->count = cont_b - 1;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int		n;
	int		cont_a;
	int		cont_b;
	t_list	*aux;

	if (!(*stack_b))
		cont_b = 0;
	else
		cont_b = (*stack_b)->count;
	if (!(*stack_a))
		return ;
	cont_a = (*stack_a)->count;
	n = (*stack_a)->content;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	free (aux);
	aux = (t_list *) malloc(sizeof (t_list));
	if (!aux)
		return ;
	aux->content = n;
	aux->next = *stack_b;
	*stack_b = aux;
	write (1, "pb\n", 3);
	(*stack_a)->count = cont_a - 1;
	(*stack_b)->count = cont_b + 1;
}
