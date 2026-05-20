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
PROJECT		= Scalar
NAME		= Scalar

# Tools
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++20

# Sources
SRC_FILES	= main.cpp ScalarConverter.cpp
SRCS		= $(addprefix src/, $(SRC_FILES))

# Objects & Dependencies
OBJS		= $(patsubst src/%.cpp, obj/%.o, $(SRCS))
OBJ_DIRS	= $(sort $(dir $(OBJS)))
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -Iinc -o $(NAME) $(OBJS)

$(OBJ_DIRS):
	mkdir -p $@

obj/%.o: src/%.cpp | $(OBJ_DIRS)
	$(CPP) $(CFLAGS) -Iinc -c $< -o $@ -MMD -MP

-include $(DEPS)

.SECONDARY: $(OBJS) 

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

exec: $(NAME)
	./$(NAME)

run: all exec

re: fclean all

.PHONY: all clean fclean re exec run
