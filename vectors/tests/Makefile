# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2022/11/16 00:40:14 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= vector

SRC_PATH		= ./
INCLUDES_PATH	= ./
OBJS_PATH		= ./objects/

SRCS_FILES =	mainFT.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.cpp, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	../vector.hpp						\
					../utils/randomAccessIterator.hpp	\
					../utils/reverseIterator.hpp		\
					../utils/iteratorTraits.hpp			\
					./includes/tests.hpp				\
					./includes/iterators.hpp				\
					./includes/utils.hpp				\
					./includes/memberFunctions.hpp		\
					./includes/operators.hpp

HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
INCLUDES	= -I$(INCLUDES_PATH)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.cpp $(HEADERS)
			@mkdir -p objects
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
			@rm -f $(OBJS)
			@rm -rf $(OBJS_PATH)
			@echo cleaned!

fclean:		clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
