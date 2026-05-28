NAME = game

ifeq ($(OS),Windows_NT)
	CXX = D:/Other/MSYS2/ucrt64/bin/g++.exe
	MAKE = D:/Other/MSYS2/ucrt64/bin/mingw32-make.exe

	RAYLIB_FLAGS =	-L./includes/raylib/src \
					-lraylib \
					-lopengl32 \
					-lgdi32 \
					-lwinmm

	EXEC = .exe
else
	CXX = c++
	MAKE = make

	RAYLIB_FLAGS =	-L./includes/raylib/src \
					-lraylib \
					-lGL \
					-lm \
					-lpthread \
					-ldl \
					-lrt \
					-lX11

	EXEC =
endif

NAME := $(NAME)$(EXEC)

CXXFLAGS = -std=c++17 -g

SRC =	main.cpp \
		srcs/Player/Player.cpp \
		srcs/Player/camera.cpp \
		srcs/Game/Game.cpp \
		srcs/Map/Tile.cpp \
		srcs/Map/Chunk.cpp \
		srcs/Map/Map.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES =	-Iincludes \
			-Iincludes/Player \
			-Iincludes/Game \
			-Iincludes/Map \
			-Iincludes/raylib/src

RAYLIB = ./includes/raylib/src/libraylib.a

all: $(NAME)

$(NAME): $(OBJ) $(RAYLIB)
	$(CXX) $(CXXFLAGS) $(OBJ) $(INCLUDES) $(RAYLIB_FLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(RAYLIB):
	$(MAKE) -C includes/raylib/src PLATFORM=PLATFORM_DESKTOP

raylib:
	$(MAKE) -C includes/raylib/src PLATFORM=PLATFORM_DESKTOP

clean:
ifeq ($(OS),Windows_NT)
	@if exist main.o del /Q main.o
	@if exist srcs\Player\Player.o del /Q srcs\Player\Player.o
	@if exist srcs\Player\camera.o del /Q srcs\Player\camera.o
	@if exist srcs\Game\Game.o del /Q srcs\Game\Game.o
	@if exist srcs\Map\Tile.o del /Q srcs\Map\Tile.o
	@if exist srcs\Map\Chunk.o del /Q srcs\Map\Chunk.o
	@if exist srcs\Map\Map.o del /Q srcs\Map\Map.o
else
	rm -f $(OBJ)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	@if exist $(NAME) del /Q $(NAME)
else
	rm -f $(NAME)
endif

re: fclean all

.PHONY: all clean fclean re raylib