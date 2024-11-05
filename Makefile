
all:
	gcc srcs/*.c -I./includes -I./minilibx-linux/ -L./minilibx-linux -lmlx -lXext -lX11 -lm -o fdf

run: all
	./fdf