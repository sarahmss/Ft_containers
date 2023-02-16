# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2023/02/15 22:23:38 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_container

SRC_PATH		= ./
INCLUDES_PATH	= ./
OBJS_PATH		= ./objects/

SRCS_FILES =	main.cpp						\
				tests/vector/vector_tests.cpp	\
				tests/map/map_tests.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.cpp, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	vector.hpp									\
					map.hpp										\
					stack.hpp									\
					tests/minunit.h								\
					tests/vector/vector_tests.hpp				\
					tests/map/map_tests.hpp						\
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

CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -fPIE -std=c++98
INCLUDES	= -I $(INCLUDES_PATH) -lrt -lm

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.cpp $(HEADERS)
			@mkdir -p objects
			@mkdir -p objects/utils
			@mkdir -p objects/tests/vector
			@mkdir -p objects/tests/map
			$(CC) $(FLAGS) -c  $< -o $@

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
