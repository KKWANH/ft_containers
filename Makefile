FT_NAME 		=	ft_containers
STL_NAME 		=	stl_containers
TESTER_NAME		=	Containers tester


SRCS_PATH		=	test_srcs/
SRCS			=	main.cpp 

CC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

FT_OBJ_PATH		=	ft_obj/
STL_OBJ_PATH	=	obj/
OBJ_NAME		=	$(SRCS:.cpp=.o)
FT_OBJ			=	$(addprefix $(FT_OBJ_PATH),$(OBJ_NAME))
STL_OBJ			=	$(addprefix $(STL_OBJ_PATH),$(OBJ_NAME))

all:
	@$(MAKE) ft || true
	@$(MAKE) stl || true
# uncomment all tests
	@sed -i '' 's/\/\/ vectorTests(vect)/vectorTests(vect)/' "$(SRCS_PATH)main.cpp"	
	@sed -i '' 's/\/\/ mapTests(map)/mapTests(map)/' "$(SRCS_PATH)main.cpp"	
	@sed -i '' 's/\/\/ stackTests(stack)/stackTests(stack)/' "$(SRCS_PATH)main.cpp"	

ft: clean $(FT_NAME)

stl: clean $(STL_NAME)

$(FT_NAME) : $(FT_OBJ)
	@$(CC) $(CFLAGS) -o $(FT_NAME) $(FT_OBJ) && ([ $$? -eq 0 ] && \
	echo "Compilation of \033[33;1m$(FT_NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m") \
	|| echo "Compilation of \033[33;1m$(FT_NAME)\033[0;1m: [\033[1;31mKO\033[0;1m]\033[0m"
	@printf "\n"

$(STL_NAME) : $(STL_OBJ)
	@$(CC) $(CFLAGS) -o $(STL_NAME) $(STL_OBJ) && ([ $$? -eq 0 ] && \
	echo "Compilation of \033[33;1m$(STL_NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m") \
	|| echo "Compilation of \033[33;1m$(STL_NAME)\033[0;1m: [\033[1;31mKO\033[0;1m]\033[0m"
	@printf "\n"
	
$(FT_OBJ_PATH)%.o:	$(SRCS_PATH)%.cpp
	@sed -i '' 's/1/0/' "$(SRCS_PATH)containers.hpp"
	@echo "\033[33m$(FT_NAME)\033[0m: namespace changed\033[0m"
	@mkdir $(FT_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@ || true
	
$(STL_OBJ_PATH)%.o:	$(SRCS_PATH)%.cpp
	@sed -i '' 's/0/1/' "$(SRCS_PATH)containers.hpp"
	@echo "\033[33m$(STL_NAME)\033[0m: namespace changed\033[0m"
	@mkdir $(STL_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@ || true

# **************************************************************************************** #
#										RUN TESTS										   #
# **************************************************************************************** #

TITLE = "\033[1m\n \
		\# ***************************************************************************** \#\n \
		\#  ____ ____ _  _ ___ ____ _ _  _ ____ ____ ____   ___ ____ ____ ___ ____ ____  \#\n \
		\#  |    |  | |\ |  |  |__| | |\ | |__  |__/ [__     |  |__  [__   |  |__  |__/  \#\n \
		\#  |___ |__| | \|  |  |  | | | \| |___ |  \ ___]    |  |___ ___]  |  |___ |  \  \#\n \
		\#                                                                               \#\n \
		\# ***************************************************************************** \#\n \
		\033[0m"
OUT_PATH	=	results/
FT_FILE		=	$(OUT_PATH)ft.out.txt
STL_FILE	=	$(OUT_PATH)stl.out.txt
DIFF_FILE	=	$(OUT_PATH)output.diff
SUCCESS		=	"\033[1m✅ Sucess ! \033[0mNo difference."
FAILURE		=	"\033[1m❌ Failure ! \033[0mDifferences in \033[4m$(DIFF_FILE)\033[0m."

map: fclean
	@echo $(TITLE)
	@echo "\t\t\t\t~ MAP ~\n"
# comment vector and stack tests
	@sed -i '' 's/vectorTests(vect)/\/\/ vectorTests(vect)/' "$(SRCS_PATH)main.cpp"	
	@sed -i '' 's/stackTests(stack)/\/\/ stackTests(stack)/' "$(SRCS_PATH)main.cpp"	
	@echo "\033[33m$(TESTER_NAME)\033[0m: tests ajusted to map container\033[0m\n"
	@$(MAKE) all
	@$(MAKE) comp

vector: fclean
	@echo $(TITLE)
	@echo "\t\t\t\t~ VECTOR ~\n"
# comment map and stack tests
	@sed -i '' 's/mapTests(map)/\/\/ mapTests(map)/' "$(SRCS_PATH)main.cpp"	
	@sed -i '' 's/stackTests(stack)/\/\/ stackTests(stack)/' "$(SRCS_PATH)main.cpp"	
	@echo "\033[33m$(TESTER_NAME)\033[0m: tests ajusted to vector container\033[0m\n"
	@$(MAKE) all
	@$(MAKE) comp

	
stack: fclean
	@echo $(TITLE)
	@echo "\t\t\t\t~ STACK ~\n"
# comment map and vector tests
	@sed -i '' 's/vectorTests(vect)/\/\/ vectorTests(vect)/' "$(SRCS_PATH)main.cpp"	
	@sed -i '' 's/mapTests(map)/\/\/ mapTests(map)/' "$(SRCS_PATH)main.cpp"	
	@echo "\033[33m$(TESTER_NAME)\033[0m: tests ajusted to stack container\033[0m\n"
	@$(MAKE) all
	@$(MAKE) comp

run: fclean title all comp

title :
	@echo $(TITLE)

comp:
	@echo
	@mkdir $(OUT_PATH) 2> /dev/null || true
	@./$(STL_NAME) > $(STL_FILE)
	@echo "\033[34m$(STL_NAME)\033[0m: outputs in \033[4m$(STL_FILE)\033[0m"
	@./$(FT_NAME) > $(FT_FILE) || echo
	@echo "\033[34m$(FT_NAME)\033[0m: outputs in \033[4m$(FT_FILE)\033[0m\n"
	@diff $(FT_FILE) $(STL_FILE) > $(DIFF_FILE) \
	&& ([ $$? -eq 0 ] && echo $(SUCCESS); rm $(DIFF_FILE)) || echo $(FAILURE)
	@echo

# **************************************************************************************** #
#											UTILS										   #
# **************************************************************************************** #

clean:
	@rm -rf $(FT_OBJ) $(FT_OBJ_PATH) $(STL_OBJ) $(STL_OBJ_PATH)
	@echo "\033[33m$(TESTER_NAME)\033[0m: objects deleted\033[0m"

fclean:	clean
	@rm -rf $(STL_FILE) $(FT_FILE) $(DIFF_FILE) $(OUT_PATH)
	@rm -rf $(FT_NAME)
	@rm -rf $(STL_NAME)
	@echo "\033[33m$(TESTER_NAME)\033[0m: cleaned up\033[0m"

re: fclean all

debug:
	@echo "\033[34;1mFT_OBJ\033[0;m\t\t= $(FT_OBJ)"
	@echo "\033[34;1mSTL_OBJ\033[0;m\t\t= $(STL_OBJ)"
	@echo "\033[34;1mSRCS PATH\033[0;m\t= $(SRCS_PATH)"
	@echo "\033[34;1mSRCS\033[0;m\t\t= $(SRCS)"
	@echo "\033[34;1mls $(SRCS_PATH)\033[0;m\t= $(shell ls $(SRCS_PATH))"

help:
	@echo Usage:
	@echo "\t[make run]     : test all containers"
	@echo "\t[make vector]  : test vector container"
	@echo "\t[make map]     : test map container"
	@echo "\t[make stack]   : test stack container"
	@echo "\t[make]         : compile FT containers and STL containers tests"
	@echo "\t[make stl]     : compile STL containers tests"
	@echo "\t[make ft]      : compile FT containers tests"
	@echo "\t[make clean]   : delete objects"
	@echo "\t[make fclean]  : [make clean] + delete executables and outputs files"
	@echo "\t[make re]      : [make fclean] and [make]"

.PHONY: all clean fclean re run stl ft getFt getStl help stack vector map title

# .IGNORE:
