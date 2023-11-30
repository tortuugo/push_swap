/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:10:36 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 16:13:22 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int	valid_input_bonus(t_list *stack)
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

void	get_input_bonus(char *argv[], t_list **stack)
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

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	s1_c;
	unsigned char	s2_c;

	i = 0;
	while ((*(s1 + i) != '\0' || *(s2 + i) != '\0') && i < n)
	{
		s1_c = s1[i];
		s2_c = s2[i];
		if (s1_c > s2_c)
			return (1);
		if (s1_c < s2_c)
			return (-1);
		i++;
	}
	return (0);
}

int	check_move(t_list **stack, t_list **stack_b, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		*stack = swap_a_bonus(*stack);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		*stack_b = swap_b_bonus(*stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		swap_ss_bonus(stack, stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		push_a_bonus(stack, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push_b_bonus(stack, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		*stack = rotate_a_bonus(*stack);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		*stack_b = rotate_b_bonus(*stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rotate_rr_bonus(stack, stack_b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		*stack = revrotate_a_bonus(*stack);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		*stack_b = revrotate_b_bonus(*stack_b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		revrotate_rr_bonus(stack, stack_b);
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack;
	t_list	*stack_b;

	stack = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	if (argv[1][0] == '\0')
	{
		write (2, "Error\n", 6);
		return (1);
	}
	get_input_bonus(argv, &stack);
	if (!stack || valid_input_bonus(stack) == 0)
		return (1);
	if (move_reader(&stack, &stack_b) == 0)
		return (1);
	valid_sol(stack, stack_b);
	free_stack(&stack);
	return (0);
}
