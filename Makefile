NAME		=	cub3d
CC			=	gcc -g

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

LIBS_DIR	= ./libs/
LIB			= -L $(LIBS_DIR)

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./mlx/
MLXNAME		=	libmlx.a

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-lmlx -Ilmlx -lXext -lX11
MLXDIR		=	./mlx_linux/
MLXNAME		=	libmlx_linux.a
endif

HEADERS		=	cub.h \
				constants.h \

SRCS		=	cub.c

all:		$(NAME)

$(NAME):	$(OBJS) libft mlx
			$(CC) $(CFLAGS) $(SRCS) $(LIB) $(MLXFLAGS) -o $(NAME)

mlx:
			@mkdir -p $(LIBS_DIR)
			@make -C $(MLXDIR)
			@cp $(MLXDIR)/$(MLXNAME) $(LIBS_DIR)

libft:
			@mkdir -p $(LIBS_DIR)
			@make -C $(LIBFT_DIR)
			@cp $(LIBFT) $(LIBS_DIR)

%o:			%.c $(HEADERS)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT_DIR)
			make clean -C $(MLXDIR)

fclean:		clean
			$(RM) $(NAME)
			rm -rf $(LIBS_DIR)
			$(RM) *.out
			make fclean -C $(LIBFT_DIR)
			make clean -C $(MLXDIR)

re:			fclean all

.PHONY:		all clean fclean re libft mlx