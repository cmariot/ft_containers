# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/07/18 17:19:50 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = map_tests



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = c++


CPPFLAGS		 = -Wall -Wextra -Werror -std=c++98 -pthread -g3


INCLUDES		 = -I includes
INCLUDES		+= -I ../framework/includes
INCLUDES		+= -I ../../containers
INCLUDES		+= -I ../../iterators


LIBRARY			 = -L ../framework -lunit



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= srcs/

SRC_SUBDIR	    = main.cpp \
				  00_map_launcher.cpp \
				  01_pair_tests.cpp \
				  02_RBTree_tests.cpp \
				  03_constructors.cpp \


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
				@-rm -f MAP.log
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
