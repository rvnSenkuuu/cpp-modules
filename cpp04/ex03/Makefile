NAME		=	AMateria
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -MMD -MP
RM			=	rm -rf

SRC			=	main.cpp \
				AMateria.cpp \
				Ice.cpp \
				Cure.cpp \
				Character.cpp \
				MateriaSource.cpp
INCLUDE		=	AMateria.hpp Ice.hpp Cure.hpp Character.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
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
	$(MAKE) all

-include $(DEP)

.PHONY: all clean fclean re