NAME		=	phonebook
CXX			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -rf

SRC			=	main.cpp \
				contact.cpp \
				phonebook.cpp \

INCLUDE		=	contact.hpp phonebook.hpp
OBJ_PATH	=	.objs/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o:	%.cpp
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean:	clean
	$(RM) $(NAME)

re:	fclean
	make all

.PHONY: all clean fclean re