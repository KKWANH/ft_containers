# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 12:29:23 by kimkwanho         #+#    #+#              #
#    Updated: 2022/01/09 15:47:04 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers

COMP		=	clang++ -Wall -Wextra -Werror -g3 -fsanitize=address -std=c++98
SRCS		=	main/main.cpp \
				main/vector.cpp \
				main/stack.cpp \
				main/map.cpp \
				main/list.cpp
OBJS		=	$(SRCS:.cpp=.o)

.cpp.o:
	@printf "\033[34m[FT_CONTAINERS]\033[0m Generating file : "
	@$(COMP) -c $< -o $(<:.cpp=.o)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

$(NAME): $(OBJS)
	@printf "\033[34m[FT_CONTAINERS]\033[0m Compiling file  : "
	@$(COMP) -o $(NAME) $(SRCS)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"
	@make clean
	@printf "\n"
	@printf "\033[34m[FT_CONTAINERS]\033[0m Now \033[32mFT_CONTAINERS\033[0m is executable. Launch this with \033[33m./ft_containers\033[0m"

all:
	@make fclean
	@$(NAME)

clean:
	@printf "\033[34m[FT_CONTAINERS]\033[0m Removing object : "
	@rm -rf $(OBJS)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

fclean:
	@make clean
	@printf "\033[34m[FT_CONTAINERS]\033[0m Removing result : "
	@rm -rf $(NAME)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

re: fclean all


