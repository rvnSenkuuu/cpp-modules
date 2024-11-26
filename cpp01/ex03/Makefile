NAME		=	weapon
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -MMD -MP
RM			=	rm -rf

SRC			=	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp
INCLUDE		=	main.h Weapon.hpp HumanA.hpp HumanB.hpp
OBJ_PATH	=	.objs/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))
DEP			=	$(OBJ:.o=.d)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o:	%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean:	clean
	$(RM) $(NAME)

re:	fclean
	make all

-include $(DEP)

.PHONY: all clean fclean re