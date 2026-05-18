# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 11:30:32 by thblack-          #+#    #+#              #
#    Updated: 2026/05/15 15:13:02 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
PROJECT		= Serializer
NAME		= Serializer

# Tools
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++20

# Sources
# SRC_FILES	=
# SRCS		= $(addprefix src/, $(SRC_FILES))
SRCS		= $(shell find -name "*.cpp")

# Objects & Dependencies
OBJS		= $(patsubst src/%.cpp, obj/%.o, $(SRCS))
OBJ_DIRS	= $(sort $(dir $(OBJ)))
DEPS		= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -Iinc -o $(NAME) $(OBJS)

$(OBJ_DIRS):
	mkdir -p $@

%.o: %.cpp
	$(CPP) $(CFLAGS) -Iinc -c $< -o $@

-include $(DEPS)

.SECONDARY: $(OBJ) 

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

exec: $(NAME)
	./$(NAME)

run: all exec

re: fclean all

.PHONY: all clean fcalean re exec run
