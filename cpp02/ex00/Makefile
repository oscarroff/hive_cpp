# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 12:34:32 by thblack-          #+#    #+#              #
#    Updated: 2026/04/08 12:36:31 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		= myfirstcanon
NAME		= myfirstcanon

CPP			= c++ -std=c++20
CFLAGS		= -Wall -Wextra -Werror

SRCS		= $(shell find . -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) .I -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CFLAGS) .I -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
