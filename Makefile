NAME		=	cub3d

HEADERS		=	cub.h \
				constants.h \
				./parsing/parsing.h

MAIN		=	cub.c

PARSING		=	./parsing/parsing.c

SRCS		=	$(MAIN)		$(PARSING)

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
			@make -s -C $(LIBFT_DIR)
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

.PHONY:		all clean fclean re