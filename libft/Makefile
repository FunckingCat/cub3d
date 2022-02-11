# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:16:17 by tyamcha           #+#    #+#              #
#    Updated: 2022/02/09 13:23:03 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_atoi.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strcmp.c ft_remove_char.c ./ft_malloc/ft_malloc.c ./ft_isstrdigit.c
BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SRC_FILES:.c=.o)
BON_OBJECTS = $(BONUS_FILES:.c=.o)

HEADER = libft.h
LIBC = ar -rc
LIBR = ranlib

ifdef TEMP
	OBJ = $(OBJECTS) $(BON_OBJECTS)
else
	OBJ = $(OBJECTS)
endif

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(LIBC) $(NAME) $(OBJ) 
	$(LIBR) $(NAME) 
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@ 

bonus :
	@make TEMP=1 all
	
clean:
	/bin/rm -f $(OBJECTS) $(BON_OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus 