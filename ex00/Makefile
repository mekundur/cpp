# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 22:18:08 by mekundur          #+#    #+#              #
#    Updated: 2025/04/01 17:36:01 by mekundur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME) 

%.o: %.cpp Makefile
	@c++ -c -g -Werror -Wall -Wextra -std=c++98 $< -o $@

$(NAME) : $(OBJ)
	@echo "Creating the executable"
	@c++ -g -Werror -Wall -Wextra -std=c++98 $(OBJ) -o $(NAME)

clean :
	@echo "Cleaning up object files"
	@rm -f $(OBJ)

fclean : clean 
	@echo "Removing the executable"
	@rm -f megaphone

re : fclean all

.PHONY: all, clean, fclean, re
