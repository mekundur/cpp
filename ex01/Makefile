# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 22:18:08 by mekundur          #+#    #+#              #
#    Updated: 2025/04/17 15:38:55 by mekundur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_phonebook
HEADER = phone.hpp
SRC = phone.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME) 

%.o: %.cpp Makefile $(HEADER)
	@c++ -c -g -Werror -Wall -Wextra -std=c++98 $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	@echo "Creating the executable"
	@c++ -g -Werror -Wall -Wextra -std=c++98 $(OBJ) -o $(NAME)

clean :
	@echo "Cleaning up object files"
	@rm -f $(OBJ)

fclean : clean 
	@echo "Removing the executable"
	@rm -f my_phonebook

re : fclean all

.PHONY: all, clean, fclean, re
