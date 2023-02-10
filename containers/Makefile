# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2023/02/10 14:07:10 by coder            ###   ########.fr        #
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
					map.hpp										\
					stack.hpp									\
					tests/minunit.h								\
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
					utils/RBT_capacity.tpp						\
					utils/RBT_iterator.tpp						\
					utils/RBT_print.tpp

HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

RED_BLACK_TREE_1		=	./tests/red_black_tree/red_black_tree.cpp

VECTOR_1				=	./tests/vector/vector.cpp

PAIR_1					=	./tests/pair/pair.cpp

CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
INCLUDES	=  -I$(INCLUDES_PATH) -lrt -lm

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.cpp $(HEADERS)
			@mkdir -p objects
			@mkdir -p objects/utils
			$(CC) $(FLAGS) -c  $< -o $@

RedBlackTree1:	$(HEADERS)
				$(CC) $(FLAGS) $(RED_BLACK_TREE_1) -o RedBlackTree1
				./RedBlackTree1

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
