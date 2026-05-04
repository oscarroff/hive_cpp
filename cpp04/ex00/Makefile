# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 12:34:32 by thblack-          #+#    #+#              #
#    Updated: 2026/05/04 18:02:41 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		= Animal
NAME		= Animal

CPP			= c++ -std=c++20
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -I. -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
