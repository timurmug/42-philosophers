# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 09:44:44 by qtamaril          #+#    #+#              #
#    Updated: 2020/11/11 12:56:20 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
INCLUDES = includes/philo_one.h

FLAGS = -Wall -Wextra -Werror -pthread
FLAGS_LIB = -Iincludes

SRCS =	srcs/ft_num.c \
		srcs/ft_str.c \
		srcs/ft_put.c \
		srcs/init.c \
		srcs/main.c \
		srcs/philo_eats.c \
		srcs/utils.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME): $(INCLUDE) $(OBJS)
	clang $(FLAGS) $(OBJS) -o $(NAME)

norme:
	@make fclean
	@echo
	norminette ./includes
	@echo
	norminette ./srcs

%.o: %.c $(INCLUDES)
	@clang $(FLAGS) $(FLAGS_LIB) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
