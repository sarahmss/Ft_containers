# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2022/12/21 23:55:38 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_container

SRC_PATH		= ./
INCLUDES_PATH	= ./
OBJS_PATH		= ./objects/

SRCS_FILES =	main.cpp			\
				utils/RBT_aux.cpp	\
				utils/RBT.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.cpp, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	./vector.hpp									\
					./utils/randomAccessIterator.hpp				\
					./utils/reverseIterator.hpp						\
					./utils/iteratorTraits.hpp						\
					./utils/equal.hpp								\
					./utils/lexicographicalCompare.hpp				\
					./utils/RBT_iterator.hpp						\
					./utils/RBT_node.hpp							\
					./utils/RBT_reverse_iterator.hpp				\
					./utils/RBT.hpp									\
					./tests/vector/tests.hpp						\
					./tests/vector/capacity.hpp						\
					./tests/vector/modifiers.hpp					\
					./tests/vector/iterators.hpp					\
					./tests/vector/utils.hpp						\
					./tests/vector/memberFunctions.hpp				\
					./tests/vector/elementAccess.hpp				\
					./tests/vector/operators.hpp

HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

RED_BLACK_TREE_1		=	./tests/red_black_tree/red_black_tree.cpp	\
							./utils/RBT_aux.cpp							\
							./utils/RBT.cpp

VECTOR_1				=	./tests/vector/vector.cpp

CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
INCLUDES	= -I$(INCLUDES_PATH)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.cpp $(HEADERS)
			@mkdir -p objects
			@mkdir -p objects/utils
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

RedBlackTree1:
				$(CC) $(FLAGS) $(RED_BLACK_TREE_1) -o RedBlackTree1
				./RedBlackTree1


Vector1:		$(HEADERS)
				$(CC) $(FLAGS) $(VECTOR_1) -o Vector1
				./Vector1


clean:
			@rm -f $(OBJS)
			@rm -rf $(OBJS_PATH)
			@rm -rf Vector1
			@rm -rf RedBlackTree1
			@echo cleaned!

fclean:		clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
