NAME = array
HEADER = Array.hpp
SRC = main.cpp
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -g -std=c++98

all : $(NAME) 

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.cpp | $(OBJDIR)
	@$(CXX) -c $(CXXFLAGS) $< -o $@

$(NAME) : $(OBJ) $(HEADER) Makefile
	@echo "Creating the executable"
	@ $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	@echo "Removing object files and objdir"
	@if [ -d $(OBJDIR) ]; then rm -f $(OBJ); rm -r $(OBJDIR); fi

fclean : clean 
	@echo "Removing the executable"
	@rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
