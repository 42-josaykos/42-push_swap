# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 10:30:02 by josaykos          #+#    #+#              #
#    Updated: 2021/03/26 10:54:57 by jonny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC_NAME = memory/ft_calloc.c \
					memory/ft_memset.c \
			  	memory/ft_bzero.c \
			  	memory/ft_memcpy.c \
			  	memory/ft_memccpy.c \
			  	memory/ft_memmove.c \
			  	memory/ft_memchr.c \
			  	memory/ft_memcmp.c \
			  	types/ft_isalpha.c \
			  	types/ft_isdigit.c \
			  	types/ft_isalnum.c \
			  	types/ft_isascii.c \
			  	types/ft_isprint.c \
			  	conversion/ft_toupper.c \
			  	conversion/ft_tolower.c \
			  	conversion/ft_atoi.c \
			  	conversion/ft_itoa.c \
			  	string/ft_strlen.c \
			  	string/ft_strchr.c \
			  	string/ft_strrchr.c \
			  	string/ft_strncmp.c \
			  	string/ft_strlcpy.c \
			  	string/ft_strldup.c \
			  	string/ft_strlcat.c \
			  	string/ft_strnstr.c \
			  	string/ft_strdup.c \
			  	string/ft_strcat.c \
			  	string/ft_substr.c \
			  	string/ft_strtrim.c \
			  	string/ft_strjoin.c \
			  	string/ft_split.c \
			  	string/ft_strmapi.c \
					string/split_whitespace.c \
			  	list/ft_lstnew.c \
			  	list/ft_lstadd_front.c \
			  	list/ft_lstsize.c \
			  	list/ft_lstlast.c \
			  	list/ft_lstadd_back.c \
			  	list/ft_lstdelone.c \
			  	list/ft_lstclear.c \
			  	list/ft_lstiter.c \
			  	list/ft_lstmap.c \
					output/ft_putchar.c \
			  	output/ft_putchar_fd.c \
			  	output/ft_putstr_fd.c \
			  	output/ft_putendl_fd.c \
			  	output/ft_putnbr_fd.c \
			  	output/ft_printf/ft_printf.c \
			  	output/ft_printf/ft_printf_checkflag.c \
			  	output/ft_printf/ft_printf_convertbase.c \
			  	output/ft_printf/ft_printf_getspecs.c \
			  	output/ft_printf/ft_printf_nbr.c \
			  	output/ft_printf/ft_printf_print.c \
			  	output/ft_printf/ft_printf_str.c \
			  	process/get_next_line/get_next_line.c \
			  	process/get_next_line/get_next_line_utils.c \

OBJ		 		= $(SRC:.c=.o)
SRC_PATH  = src
SRC 			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))

RM 				= rm -rf
CC 				= clang
MEM				= -g -O3 -fsanitize=address
INCLUDES 	= -Iincludes

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: clean fclean all
