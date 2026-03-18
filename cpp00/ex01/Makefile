# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 11:30:32 by thblack-          #+#    #+#              #
#    Updated: 2026/03/18 16:41:29 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
PROJECT		= PhoneBook
NAME		= PhoneBook

# Tools
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror

# Sources
SRCS		= main.cpp PhoneBook.cpp Contact.cpp Utils.cpp

# Objects
OBJS		= $(SRCS:.cpp=.o)

# Includes
HEADER		= Awesome.hpp
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
