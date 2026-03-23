# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 11:30:32 by thblack-          #+#    #+#              #
#    Updated: 2026/03/23 11:51:30 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
PROJECT		= moarBrainz
NAME		= moarBrainz

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
HEADER		= 
INC			= -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADER)
	$(CPP) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
