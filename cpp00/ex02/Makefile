# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 11:30:32 by thblack-          #+#    #+#              #
#    Updated: 2026/03/18 16:52:26 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
PROJECT		= DreamJob
NAME		= DreamJob

# Tools
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror

# Sources
SRCS		= tests.cpp Account.cpp

# Objects
OBJS		= $(SRCS:.cpp=.o)

# Includes
HEADER		= Account.hpp
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
