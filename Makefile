# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 13:33:45 by egomez-g          #+#    #+#              #
#    Updated: 2023/11/21 19:24:15 by egomez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SOURCES =		push_swap.c list.c ft_atoi.c ft_split.c f_swap.c \
				f_push.c f_revrotate.c f_rotate.c algoritmo.c \
				utils.c cost.c

SOURCES_BONUS =		checker.c f_push_bonus.c f_swap_bonus.c f_rotate_bonus.c \
					f_revrotate_bonus.c get_next_line.c get_next_line_utils.c \
					list.c ft_atoi.c ft_split.c checker_utils.c \

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

all : $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

bonus: $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)

fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(NAME_BONUS)

re: fclean all
