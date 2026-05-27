NAME = game

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		srcs/player/Player.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES =	-Iincludes \
			-Iincludes/Player \
			-Iincludes/raylib

RAYLIB = ./raylib/src/libraylib.a

LIBS = -L./raylib/src \
	-lraylib \
	-lGL \
	-llm \
	-lpthread \
	-ldl \
	-lrt \
	-lX11

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(INCLUDES) $(RAYLIB) $(LIBS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re