/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:48:36 by egomez-g          #+#    #+#             */
/*   Updated: 2023/11/23 16:13:41 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char		*get_next_line(int fd);
char		*free_all(char **file);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s1);
char		*ft_substr(char *s, unsigned int start, size_t len);

void		valid_sol(t_list *stack, t_list *stack_b);
int			move_reader(t_list **stack, t_list **stack_b);
int			check_move(t_list **stack, t_list **stack_b, char *move);

void		push_a_bonus(t_list **stack_a, t_list **stack_b);
void		push_b_bonus(t_list **stack_a, t_list **stack_b);
t_list		*swap_a_bonus(t_list *stack);
t_list		*swap_b_bonus(t_list *stack);
void		swap_ss_bonus(t_list **stack_a, t_list **stack_b);
t_list		*rotate_a_bonus(t_list *stack);
t_list		*rotate_b_bonus(t_list *stack);
void		rotate_rr_bonus(t_list **stack_a, t_list **stack_b);
t_list		*revrotate_a_bonus(t_list *stack);
t_list		*revrotate_b_bonus(t_list *stack);
void		revrotate_rr_bonus(t_list **stack_a, t_list **stack_b);

#endif
