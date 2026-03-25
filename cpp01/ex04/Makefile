# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 11:30:32 by thblack-          #+#    #+#              #
#    Updated: 2026/03/25 17:10:09 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
PROJECT		= loserSed
NAME		= loserSed

# Tools
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror

# Sources
SRCS		= main.cpp

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
