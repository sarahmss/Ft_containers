# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2023/01/25 18:41:08 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_container

SRC_PATH		= ./
INCLUDES_PATH	= ./
OBJS_PATH		= ./objects/

SRCS_FILES =	main.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.cpp, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	vector.hpp									\
					utils/randomAccessIterator.hpp				\
					utils/reverseIterator.hpp					\
					utils/iteratorTraits.hpp					\
					utils/equal.hpp								\
					utils/lexicographicalCompare.hpp			\
					utils/RBT_iterator.hpp						\
					utils/RBT_node.hpp							\
					utils/RBT_reverse_iterator.hpp				\
					utils/RBT.hpp								\
					utils/RBT.tpp								\
					utils/RBT_private.tpp						\
					utils/RBT_print.tpp							\
					tests/vector/tests.hpp						\
					tests/vector/capacity.hpp					\
					tests/vector/modifiers.hpp					\
					tests/vector/iterators.hpp					\
					tests/vector/utils.hpp						\
					tests/vector/memberFunctions.hpp			\
					tests/vector/elementAccess.hpp				\
					tests/vector/operators.hpp

HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

RED_BLACK_TREE_1		=	./tests/red_black_tree/red_black_tree.cpp

VECTOR_1				=	./tests/vector/vector.cpp

PAIR_1					=	./tests/pair/pair.cpp

CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
INCLUDES	= -I$(INCLUDES_PATH)

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.cpp $(HEADERS)
			@mkdir -p objects
			@mkdir -p objects/utils
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

RedBlackTree1:
				$(CC) $(FLAGS) $(RED_BLACK_TREE_1) -o RedBlackTree1
#				./RedBlackTree1


Vector1:		$(HEADERS)
				$(CC) $(FLAGS) $(VECTOR_1) -o Vector1
				./Vector1

Pair1:
				$(CC) $(FLAGS) $(PAIR_1) -o Pair1
				./Pair1

clean:
			@rm -f $(OBJS)
			@rm -rf $(OBJS_PATH)
			@rm -rf Vector1
			@rm -rf RedBlackTree1
			@rm -rf Pair1
			@echo cleaned!

fclean:		clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
