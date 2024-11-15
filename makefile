# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 17:43:58 by mokariou          #+#    #+#              #
#    Updated: 2024/11/15 17:47:20 by mokariou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
GFLAGS = -Wall -Wextra -Werror
NORM = norminette

OBJ_DIR = obj/
SRC = src/pipex.c src/utils.c

SRCPR = utils/printf/ft_address.c utils/printf/ft_print_hex.c \
		utils/printf/ft_printf.c utils/printf/ft_unsigned.c \
		utils/printf/printnum.c utils/printf/putstr.c

SRC_LIBFT = utils/libft/ft_atoi.c utils/libft/ft_bzero.c utils/libft/ft_calloc.c \
	utils/libft/ft_isalnum.c utils/libft/ft_isalpha.c utils/libft/ft_isascii.c \
			utils/libft/ft_isdigit.c utils/libft/ft_isprint.c utils/libft/ft_itoa.c \
			utils/libft/ft_lstadd_back_bonus.c utils/libft/ft_lstadd_front_bonus.c \
			utils/libft/ft_lstclear_bonus.c utils/libft/ft_lstdelone_bonus.c \
			utils/libft/ft_lstiter_bonus.c utils/libft/ft_lstlast_bonus.c \
			utils/libft/ft_lstmap_bonus.c utils/libft/ft_lstnew_bonus.c \
			utils/libft/ft_lstsize_bonus.c utils/libft/ft_memchr.c \
			utils/libft/ft_memcmp.c utils/libft/ft_memcpy.c utils/libft/ft_memmove.c \
			utils/libft/ft_memset.c utils/libft/ft_putchar_fd.c utils/libft/ft_putendl_fd.c \
			utils/libft/ft_putnbr_fd.c utils/libft/ft_putstr_fd.c utils/libft/ft_split.c \
			utils/libft/ft_strchr.c utils/libft/ft_strdup.c utils/libft/ft_striteri.c \
			utils/libft/ft_strjoin.c utils/libft/ft_strlcat.c utils/libft/ft_strlcpy.c \
			utils/libft/ft_strlen.c utils/libft/ft_strmapi.c utils/libft/ft_strncmp.c \
			utils/libft/ft_strnstr.c utils/libft/ft_strrchr.c utils/libft/ft_strtrim.c \
			utils/libft/ft_substr.c utils/libft/ft_tolower.c utils/libft/ft_toupper.c

SRCS = $(SRC) $(SRCPR) $(SRC_LIBFT)
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(GFLAGS) $(OBJ) -o $(NAME)


$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	$(NORM)