NAME		=	ft_containers

COMP		=	clang++
FLAG		=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main/main.cpp

PCON		=	containers/
HCON		=	vector.hpp \
				list.hpp \
				stack.hpp \
				map.hpp

PTEM		=	templates/
HTEM		=	type1_or_type2.hpp \
				stl_like.hpp

PITE		=	iterators/
HITE		=	vector_iterator.hpp \
				rev_vector_iterator.hpp \
				list_iterator.hpp \
				rev_list_iterator.hpp \
				map_iterator.hpp \
				rev_map_iterator.hpp

OBJS		=	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	@printf "\033[34m[FT_CONTAINERS]\033[0m Compiling file  : "
	@$(COMP) -o $(NAME) $(FLAG) $(OBJS)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"
	@make clean
	@printf "\n"
	@printf "\033[34m[FT_CONTAINERS]\033[0m Now \033[32mFT_CONTAINERS\033[0m is executable. Launch this with \033[33m./ft_containers\033[0m"

all: 
	@make fclean
	$(NAME)

$(OBJS): $(addprefix $(PCON), $(HCON)) $(addprefix $(PTEM), $(HTEM)) $(addprefix $(PITE), $(HITE))

clean:
	@printf "\033[34m[FT_CONTAINERS]\033[0m Removing object : "
	@rm -rf $(OBJS)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

fclean: clean
	@printf "\033[34m[FT_CONTAINERS]\033[0m Removing result : "
	@rm -rf $(NAME)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

re: fclean all

%.o: %.cpp
	@printf "\033[34m[FT_CONTAINERS]\033[0m Generating file : "
	@$(COMP) $(FLAG) -o $@ -c $<
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"


