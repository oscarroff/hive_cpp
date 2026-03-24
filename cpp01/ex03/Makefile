# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 11:30:32 by thblack-          #+#    #+#              #
#    Updated: 2026/03/23 11:54:01 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
PROJECT		= unnecessaryViolence
NAME		= unnecessaryViolence

# Tools
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror

# Sources
SRCS_FILES	=
SRCS_DEV	= $(shell find -name "*.cpp")
SRCS		= $(SRCS_DEV)

# Objects
OBJS		= $(SRCS:.cpp=.o)

# Includes
INC			= -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
