NAME		=	cub3D

HEADERS		=	./cub.h \
				./constants.h \
				./error/error.h \
				./state/state.h \
				./parsing/parsing.h \
				./hooks/hooks.h \
				./render/render.h \
				./vector/vector.h 

MAIN		=	./cub.c

STATE	=		./state/state.c

ERROR		=	./error/error.c

PARSING		=	./parsing/parse_map.c \
				./parsing/parse_utils.c \
				./parsing/validate.c \
				./parsing/check_map.c

HOOKS		=	./hooks/set_hooks.c

RENDER		=	./render/render.c \
				./render/image.c \
				./render/minimap.c \
				./render/render_walls.c \
				./render/raycasting.c

VECT		=	./vector/vec_add.c \
				./vector/vec_dot.c \
				./vector/vec_len.c \
				./vector/vec_mul.c \
				./vector/vec_new.c \
				./vector/vec_norm.c \
				./vector/vec_rot.c \
				./vector/vec_sub.c \
				./vector/vec_dist.c \
				./vector/vec_scal_prod.c

SRCS		=	$(MAIN)		$(PARSING)	$(ERROR) \
				$(HOOKS)	$(STATE)	$(RENDER) \
				$(RAYCAST)	$(VECT)		$(DRAW)

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc -pg
# CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft

MLXFLAGS	=	-L ./libmlx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./libmlx/

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./libmlx_linux/ -lmlx -Ilmlx -lXext -lX11
MLXDIR		=	./libmlx_linux/
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
			$(RM) ./gmon.out
			make clean -s -C $(LIBFT_DIR)
			make clean -s -C $(MLXDIR)

re:			fclean all

run:		all
			./cub3D ./maps/map1.cub

prof:		all
			./cub3D ./maps/map1.cub && gprof ./cub3D | head -n 50

val:		all
			valgrind ./cub3D ./maps/map1.cub

.PHONY:		all clean fclean re run val