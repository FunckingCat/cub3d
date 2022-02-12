NAME		=	cub3D

HEADERS		=	cub.h \
				constants.h \
				./error/error.h \
				./map/map.h \
				./parsing/parsing.h \
				./hooks/hooks.h \
				./state/state.h

MAIN		=	cub.c

STATE		=	./state/state.c

ERROR		=	./error/error.c

PARSING		=	./parsing/parse_map.c \
				./parsing/parse_utils.c \
				./parsing/validate.c \
				./parsing/check_map.c

HOOKS		=	./hooks/keypress.c

MAP			=	./map/map.c

SRCS		=	$(MAIN)		$(PARSING)	$(ERROR)	$(MAP) \
				$(STATE)	$(HOOKS)


OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
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

$(NAME):	$(OBJS)
			@make -s -C $(MLXDIR)
			@make bonus -s -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLXFLAGS)

%o:			%.c $(HEADERS) Makefile
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

.PHONY:		all clean fclean re run