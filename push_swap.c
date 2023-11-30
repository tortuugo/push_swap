/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:38:18 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 16:27:01 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int	flag;

	flag = 0;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			flag = 1;
		stack = stack->next;
	}
	return (flag);
}

int	valid_input(t_list *stack)
{
	t_list	*i;
	t_list	*reset;

	reset = stack;
	while (stack->next)
	{
		i = reset;
		while (i)
		{
			if (stack->content == i->content && stack != i)
			{
				write (2, "Error\n", 6);
				return (0);
			}
			i = i->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	get_input(char *argv[], t_list **stack)
{
	int		i;
	int		j;
	char	**input;

	*stack = NULL;
	i = 1;
	while (argv[i])
	{
		input = ft_split(argv[i], ' ');
		if (!input)
			return ;
		if (input[0] == NULL)
			return ;
		new_stack(input, stack);
		j = 0;
		while (input[j])
		{
			free (input[j]);
			j++;
		}
		free (input);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack;
	t_list	*stack_b;

	stack = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (argv[1][0] == '\0')
		write (2, "Error\n", 6);
	get_input(argv, &stack);
	if (!stack || valid_input(stack) == 0
		|| is_sorted(stack) == 0)
		return (1);
	if (stack->count == 2)
		stack = only2(stack);
	else if (stack->count == 3)
		stack = last_three(stack);
	else
		init_do(&stack, &stack_b);
	free_stack(&stack);
	stack = NULL;
	return (0);
}
