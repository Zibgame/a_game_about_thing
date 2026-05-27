NAME = game

CXX = c++

CXXFLAGS = -std=c++17 -g

SRC =	main.cpp \
		srcs/Player/Player.cpp \
		srcs/Game/Game.cpp \
		srcs/Map/Tile.cpp \
		srcs/Map/Chunk.cpp \
		srcs/Map/Map.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES =	-Iincludes \
			-Iincludes/Player \
			-Iincludes/Game \
			-Iincludes/Map \
			-Iincludes/raylib/src \
			-Iincludes/FastNoiseLite/Cpp

RAYLIB = ./includes/raylib/src/libraylib.a

LIBS = -L./includes/raylib/src \
	-lraylib \
	-lGL \
	-lm \
	-lpthread \
	-ldl \
	-lrt \
	-lX11

$(NAME): $(OBJ) $(RAYLIB)
	$(CXX) $(CXXFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(RAYLIB):
	make -C includes/raylib/src

raylib:
	make -C includes/raylib/src

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re raylib