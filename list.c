/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:51:24 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 15:09:12 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*free_stack(t_list **stack)
{
	t_list	*i;
	t_list	*next_node;

	i = *stack;
	while (i)
	{
		next_node = i->next;
		free (i);
		i = next_node;
	}
	*stack = NULL;
	return (NULL);
}

void	add_stack(int n, t_list **stack)
{
	t_list	*nodo;
	t_list	*i;

	nodo = (t_list *) malloc (sizeof(t_list));
	if (!nodo)
		return ;
	nodo->content = n;
	nodo->next = NULL;
	nodo->cost = 0;
	i = *stack;
	if (*stack)
	{
		while (i->next)
			i = i->next;
		i->next = nodo;
	}
	else
		*stack = nodo;
	(*stack)->count++;
}

void	new_stack(char **input, t_list **stack)
{
	int			j;
	long int	num;

	j = 0;
	while (input[j])
	{
		num = ft_atoi(input[j]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_stack(stack);
			write (2, "Error\n", 6);
			return ;
		}
		add_stack(num, stack);
		j++;
	}
}
