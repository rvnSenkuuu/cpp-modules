NAME		=	Convert
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -MMD -MP
RM			=	rm -rf

SRC			=	main.cpp \
				ScalarConvert.cpp \
				ScalarConvertFunction.cpp
INCLUDE		=	ScalarConvert.hpp
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