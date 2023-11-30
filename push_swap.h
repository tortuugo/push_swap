/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:17:20 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/21 18:11:41 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				pos;
	int				cost;
	struct s_list	*true_pos;
	struct s_list	*next;
	int				count;
}					t_list;

char		**ft_split(char const *s, char c);
long int	ft_atoi(char *str);

void		add_stack(int n, t_list **stack);
void		new_stack(char **input, t_list **stack);
char		*free_stack(t_list **stack);
t_list		*swap_a(t_list *stack, t_list *n_stack);
t_list		*swap_b(t_list *stack, t_list *n_stack);
void		swap_ss(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_a, t_list **stack_b);
t_list		*revrotate_a(t_list *stack);
t_list		*revrotate_b(t_list *stack);
void		revrotate_rr(t_list **stack_a, t_list **stack_b);
t_list		*rotate_a(t_list *stack);
t_list		*rotate_b(t_list *stack);
void		rotate_rr(t_list **stack_a, t_list **stack_b);

int			valid_input(t_list *stack);
void		get_input(char *argv[], t_list **stack);
int			valid_input(t_list *stack_a);
t_list		*last_node(t_list *stack);
t_list		*last_three(t_list *stack_a);
t_list		*only2(t_list *stack);
void		final_sort(t_list **stack_a, t_list **stack_b);
void		init_do(t_list **stack_a, t_list **stack_b);
void		set_cost(t_list **stack);
void		set_true_stack(t_list **stack_a, t_list *stack_b);
t_list		*find_max(t_list *stack);
int			rrr_cost(t_list *a, t_list *b, int cont);
t_list		*lower_cost(t_list *stack, t_list *stack_b);
void		finish_rotate(t_list *move, t_list **stack_a, t_list **stack_b);
void		decision(t_list **stack_a, t_list **stack_b);
void		check_stack_b(t_list **stack);

#endif
