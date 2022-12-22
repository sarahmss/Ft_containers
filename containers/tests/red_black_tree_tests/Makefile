# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2022/12/21 23:07:51 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rbt

SRC_PATH		= ./
INCLUDES_PATH	= ./../../utils/
OBJS_PATH		= ./objects/

SRCS_FILES =	main.cpp						\
				$(INCLUDES_PATH)RBT_aux.cpp		\
				$(INCLUDES_PATH)RBT.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.cpp, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	RBT.hpp						\
					RBT_iterator.hpp			\
					RBT_reverse_iterator.hpp	\
					iteratorTraits.hpp			\
					pair.hpp					\
					RBT_node.hpp				\

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
