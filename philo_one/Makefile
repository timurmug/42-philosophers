# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 09:44:44 by qtamaril          #+#    #+#              #
#    Updated: 2020/11/07 10:49:10 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
INCLUDES = includes/philo_one.h

FLAGS = -Wall -Wextra -Werror -pthread
FLAGS_LIB = -Iincludes

SRCS =	srcs/main.c \
				utils/ft_putendl_fd.c \
				utils/ft_putstr_fd.c \
				utils/ft_putnbr_fd.c \
				utils/ft_putchar_fd.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME): $(INCLUDE) $(OBJS)
	clang $(FLAGS) $(OBJS) -o $(NAME)
	@echo "----------------------"
	./$(NAME)

norme:
	@make fclean
	@echo
	norminette ./srcs

%.o: %.c $(INCLUDES)
	@clang $(FLAGS) $(FLAGS_LIB) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
