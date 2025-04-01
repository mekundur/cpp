# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 22:18:08 by mekundur          #+#    #+#              #
#    Updated: 2025/03/26 23:21:12 by mekundur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME) 

%.o: %.c Makefile
	@cc -c -g -Werror -Wall -Wextra $< -o $@

$(NAME) : $(OBJECTS) $(HEADER)
	@echo "Creating the library <libft.a>"
	@ar -rcs $@ $(OBJECTS)

clean :
	@echo "Cleaning up object files"
	@rm -f $(OBJECTS)

fclean : clean 
	@echo "Removing the library <libft.a>"
	@rm -f libft.a

re : fclean all

.PHONY: all, clean, fclean, re
