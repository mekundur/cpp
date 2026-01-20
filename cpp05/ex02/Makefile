NAME = bureaucrat
HEADER = Bureaucrat.hpp AForm.hpp \
		ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRC = main.cpp Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -g -std=c++98

all : $(NAME) 

debug: CXXFLAGS += -DDEBUG
debug: re

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
