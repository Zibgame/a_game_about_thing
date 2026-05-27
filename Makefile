NAME = game

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++17

RAYLIB_DIR = includes/raylib/src

INCLUDES =	-Iincludes \
			-Iincludes/Player \
			-I$(RAYLIB_DIR)

LIBS =	$(RAYLIB_DIR)/libraylib.a \
		-ldl \
		-lpthread \
		-lm \
		-lX11

SRCS =	main.cpp \
		srcs/player/Player.cpp

OBJS = $(SRCS:.cpp=.o)

all: raylib $(NAME)

raylib:
	make -C $(RAYLIB_DIR) PLATFORM=PLATFORM_DESKTOP GLFW_LINUX_ENABLE_WAYLAND=OFF

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(RAYLIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re raylib