# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 09:44:44 by qtamaril          #+#    #+#              #
#    Updated: 2020/11/17 11:19:58 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three
INCLUDES = includes/philo_three.h

FLAGS = -Wall -Wextra -Werror -pthread
FLAGS_LIB = -Iincludes

SRCS =	srcs/ft_num.c \
		srcs/ft_str.c \
		srcs/ft_put.c \
		srcs/init_and_eats.c \
		srcs/main.c \
		srcs/utils.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME): $(INCLUDES) $(OBJS)
	clang $(FLAGS) $(OBJS) -o $(NAME)

norme:
	@make fclean
	@echo
	norminette ./includes
	@echo
	norminette ./srcs

%.o: %.c
	@clang $(FLAGS) $(FLAGS_LIB) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
