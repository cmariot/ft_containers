# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/06/14 20:18:53 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = vector_tests



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = c++


CPPFLAGS		 = -Wall -Wextra -Werror -std=c++98 -pthread -g3


INCLUDES		 = -I includes
INCLUDES		+= -I ../framework/includes
INCLUDES		+= -I ../../containers


LIBRARY			 = -L ../framework -lunit



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= srcs/

SRC_SUBDIR	    = main.cpp \
				  00_vector_launcher.cpp \
				  01_constructor_tests.cpp \
				  02_destructor_tests.cpp \
				  03_operator_equal_tests.cpp \
				  04_iterators.cpp \
				  05_size.cpp \
				  06_max_size.cpp \
				  07_resize.cpp \
				  08_capacity.cpp \
				  09_empty.cpp \
				  10_reserve.cpp \
				  11_operators.cpp \
				  12_at.cpp \
				  13_front.cpp \
				  14_back.cpp \
				  15_assign.cpp \
				  16_push_back.cpp \
				  17_pop_back.cpp \
				  18_insert.cpp \
				  19_erase.cpp \
				  20_swap.cpp \
				  21_clear.cpp \
				  22_allocator.cpp \
				  23_relational.cpp \
				  24_swap.cpp \


SRCS			= $(addprefix $(SRC_ROOTDIR), $(SRC_SUBDIR))



# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


OBJ_ROOTDIR		= objs/

OBJ_SUBDIR		= $(SRC_SUBDIR:.cpp=.o)

OBJ_DIR 		= $(shell find ./srcs -type d | sed s/".\/srcs"/".\/objs"/g)

OBJS			= $(addprefix $(OBJ_ROOTDIR), $(OBJ_SUBDIR))

DEPENDS			:= $(OBJS:.o=.d)



# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #


RED				= \033[31;1m
CYAN			= \033[36;1m
RESET			= \033[0m



# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


.SILENT : 		all


all : 			header $(NAME) footer


$(OBJ_ROOTDIR)%.o: $(SRC_ROOTDIR)%.cpp
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CPPFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


$(NAME)	: 		$(OBJS)
				@make -C ../framework --no-print-directory
				$(CC) $(CPPFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
				@printf "\n"


leaks :			all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=66 ./$(NAME) 2> valgrind.log


showleaks :		all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=66 ./$(NAME)


test :			all
				@./$(NAME)


clean :
				@rm -rf $(OBJ_ROOTDIR)
				@make clean -C ../framework --no-print-directory
				@printf "$(RED)"
				@printf "Object files removed\n"
				@printf "$(RESET)"


fclean :
				@-rm -f $(NAME)
				@-rm -rf $(OBJ_ROOTDIR)
				@-rm -f VECTOR.log
				@-rm -f valgrind.log
				@make fclean -C ../framework --no-print-directory
				@printf "$(RED)"
				@printf "Binary and object files removed\n"
				@printf "$(RESET)"


re :			fclean all


header :
				@printf "$(CYAN)"
				@printf "VECTOR TESTS COMPILATION\n"
				@printf "$(RESET)"


footer :
				@printf "$(CYAN)"
				@printf "➤     SUCCESS\n"
				@printf "\nUSAGE\n"
				@printf "$(RESET)"
				@printf "./$(NAME)\n"


-include $(DEPENDS)


.PHONY : 		all clean fclean bonus re
