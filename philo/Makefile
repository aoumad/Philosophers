# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 23:35:41 by aoumad            #+#    #+#              #
#    Updated: 2022/11/25 18:37:44 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC 	= includes/philo.h

SRC		=	srcs/operations/ft_eating_case.c \
			srcs/operations/ft_routine.c srcs/operations/ft_sleeping_thinking.c \
			srcs/operations/ft_taking_forks.c srcs/parsing/ft_init_args.c \
			srcs/parsing/ft_mutex_destroy.c srcs/parsing/ft_init_mutex.c \
			srcs/parsing/ft_create_philos.c srcs/parsing/ft_valid_args.c \
			srcs/ft_tools/ft_atoi.c srcs/ft_tools/ft_calloc.c srcs/ft_tools/ft_cout.c \
			srcs/ft_tools/ft_time_calcul.c srcs/ft_tools/ft_putstr_fd.c srcs/philo.c \
			srcs/ft_tools/ft_help_menu.c srcs/ft_tools/ft_isdigit.c

CC 		= gcc

FLAGS	= -g -Wall -Wextra -Werror -pthread

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS) $(INC)

%.o: %.c $(INC)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re