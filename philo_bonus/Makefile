# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 23:35:41 by aoumad            #+#    #+#              #
#    Updated: 2022/08/04 12:52:27 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

INC 	= includes/philo_bonus.h

SRC		=	srcs/operations/ft_create_philos.c srcs/operations/ft_death_checker.c \
			srcs/operations/ft_philo_routine.c \
			srcs/parsing/ft_init_args.c srcs/parsing/ft_init_semaphore.c \
			srcs/ft_tools/ft_kill.c srcs/parsing/ft_valid_args.c\
			srcs/ft_tools/ft_atoi.c srcs/ft_tools/ft_calloc.c srcs/ft_tools/ft_cout.c \
			srcs/ft_tools/ft_time_calcul.c srcs/ft_tools/ft_putstr_fd.c \
			srcs/ft_tools/ft_help_menu.c \
			srcs/philo_bonus.c

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
