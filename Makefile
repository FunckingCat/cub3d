NAME		=	cub3D

HEADERS		=	./cub.h \
				./constants.h \
				./error/error.h \
				./map/map.h \
				./parsing/parsing.h \
				./hooks/hooks.h \
				./state/state.h \
				./player/player.h \
				./render/render.h \
				./vector/vector.h \
				./draw/draw.h \
				./raycasting/raycasting.h

MAIN		=	./cub.c

STATE		=	./state/state.c

ERROR		=	./error/error.c

PARSING		=	./parsing/parse_map.c \
				./parsing/parse_utils.c \
				./parsing/validate.c \
				./parsing/check_map.c

HOOKS		=	./hooks/keypress.c \
				./hooks/set_hooks.c

MAP			=	./map/map.c

PLAYER		=	./player/player.c

RENDER		=	./render/render.c \
				./render/image.c \
				./render/minimap.c

DRAW		=	./draw/draw_map.c \
				./draw/line.c \
				./draw/line_utils.c \
				./draw/rectangle.c

RAYCAST		=	./raycasting/raycasting.c

VECT		=	./vector/vec_add.c \
				./vector/vec_dot.c \
				./vector/vec_len.c \
				./vector/vec_mul.c \
				./vector/vec_new.c \
				./vector/vec_norm.c \
				./vector/vec_rot.c \
				./vector/vec_sub.c \
				./vector/vec_dist.c \
				./vector/vec_scal_prod.c \
				./vector/print_vec.c

SRCS		=	$(MAIN)		$(PARSING)	$(ERROR)	$(MAP) \
				$(STATE)	$(HOOKS)	$(PLAYER)	$(RENDER) \
				$(RAYCAST)	$(VECT)		$(DRAW)

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc -g -fsanitize=address
# CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft

MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./mlx/

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
MLXDIR		=	./mlx_linux/
endif

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			@make -s -C $(MLXDIR)
			@make bonus -s -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLXFLAGS) -lm

%.o : %.c $(HEADERS)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make clean -s -C $(LIBFT_DIR)
			make clean -s -C $(MLXDIR)

re:			fclean all

run:		all
			./cub3D ./maps/map1.cub

val:		all
			valgrind ./cub3D ./maps/map1.cub

.PHONY:		all clean fclean re run val