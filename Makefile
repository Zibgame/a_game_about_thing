NAME = game

CXX = c++

CXXFLAGS = -std=c++17 -g

# ─── Détection de l'OS ────────────────────────────────────────────────────────
ifeq ($(OS), Windows_NT)
    PLATFORM   = WINDOWS
    NAME       = game.exe
    FIXPATH    = $(subst /,\,$1)
    OBJ_EXT    = .obj
    RAYLIB     = includes\raylib\src\libraylib.a
    LIBS       = -L./includes/raylib/src \
                 -lraylib \
                 -lopengl32 \
                 -lgdi32 \
                 -lwinmm \
                 -lm \
                 -lpthread
    MAKE_CMD   = mingw32-make
else
    PLATFORM   = LINUX
    FIXPATH    = $1
    OBJ_EXT    = .o
    RAYLIB     = ./includes/raylib/src/libraylib.a
    LIBS       = -L./includes/raylib/src \
                 -lraylib \
                 -lGL \
                 -lm \
                 -lpthread \
                 -ldl \
                 -lrt \
                 -lX11
    MAKE_CMD   = make
endif

# ─── Sources & objets ─────────────────────────────────────────────────────────
SRC =   main.cpp \
        srcs/Player/Player.cpp \
        srcs/Player/camera.cpp \
        srcs/Game/Game.cpp \
        srcs/Map/Tile.cpp \
        srcs/Map/Chunk.cpp \
        srcs/Map/Map.cpp

OBJ_O   = $(SRC:.cpp=.o)
OBJ_OBJ = $(SRC:.cpp=.obj)
OBJ     = $(SRC:.cpp=$(OBJ_EXT))

# ─── Includes & Raylib ────────────────────────────────────────────────────────
INCLUDES =  -Iincludes \
            -Iincludes/Player \
            -Iincludes/Game \
            -Iincludes/Map \
            -Iincludes/raylib/src

# ─── Règles ───────────────────────────────────────────────────────────────────
$(NAME): $(OBJ) $(RAYLIB)
	$(CXX) $(CXXFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

%$(OBJ_EXT): %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(RAYLIB):
	$(MAKE_CMD) -C includes/raylib/src

raylib:
	$(MAKE_CMD) -C includes/raylib/src

all: $(NAME)

clean:
ifeq ($(PLATFORM), WINDOWS)
	powershell -Command "Get-ChildItem -Recurse -Include *.o,*.obj | Remove-Item -Force"
else
	rm -f $(OBJ_O) $(OBJ_OBJ)
endif

fclean: clean
ifeq ($(PLATFORM), WINDOWS)
	powershell -Command "if (Test-Path $(NAME)) { Remove-Item -Force $(NAME) }"
else
	rm -f $(NAME)
endif

re: fclean all

.PHONY: all clean fclean re raylib