NAME		=	cub3d
CC			=	gcc

LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

LIBS_DIR	= ./libs/

MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./mlx/
MLXNAME		=	libmlx.a

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
MLXDIR		=	./mlx_linux/
MLXNAME		=	libmlx_linux.a
endif

HEADERS		=	cub.h \
				constants.h \

SRCS		=	cub.c

all:		$(NAME)

$(NAME):	$(OBJS) libft mlx
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

mlx:
			@mkdir -p $(LIBS_DIR)
			@make -C $(MLXDIR)
			cp $(MLXDIR)/$(MLXNAME) $(LIBS_DIR)

libft:
			@mkdir -p $(LIBS_DIR)
			@make -C $(LIBFT_DIR)
			@cp $(LIBFT) $(LIBS_DIR)

%o:			%.c $(HEADERS)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all
			./$(NAME) maps/map_bonus.ber

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# To call: make git m="my commit"

.PHONY:		all clean fclean re libft mlx