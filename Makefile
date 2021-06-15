# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:36:59 by jonny             #+#    #+#              #
#    Updated: 2021/06/15 11:01:04 by jonny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries
NAME = checkers/checker
NAME2 = push_swap

# Compilation
CC = clang
CFLAGS = -Wall -Wextra -Werror
MEM = -g -O3 -fsanitize=address

# Directories
SRCSFD = src/
OBJSFD = obj/
CHKERFD = checker_src/
PUSHSWAPFD = push_swap_src/
COREFD = core_src/

# Sources
CHKER_SRC = main.c \
						checker.c \
						instructions.c \

PUSHSWAP_SRC =	main.c \
								push_swap.c \
								sorting_algo1.c \
								sorting_algo2.c \
								sorting_algo3.c \
								exec_inst.c \

CORE_SRC = strings.c \
						arrays.c \
						errors.c \
						parsing.c \
						swap.c \
						rotate.c \
						push.c \
						free_all.c \
						stack_init.c \
						stack_utils.c \

# Objects
CHKER_OBJ = $(addprefix $(OBJSFD)$(CHKERFD),$(CHKER_SRC:.c=.o))
PUSHSWAP_OBJ = $(addprefix $(OBJSFD)$(PUSHSWAPFD),$(PUSHSWAP_SRC:.c=.o))
CORE_OBJ = $(addprefix $(OBJSFD)$(COREFD),$(CORE_SRC:.c=.o))

# Libft / Includes
LIBFT = libft/libft.a
INCLUDES = -Iincludes -Ilibft/includes

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: libft project $(NAME) $(NAME2)
	@echo "$(GREEN)Project ready$(NONE)"

libft:
	@echo "$(GREEN)Checking libft...$(NONE)"
	@make -C libft 1>/dev/null

project:
	@echo "$(GREEN)Checking project...$(NONE)"

# Obj directories
$(OBJSFD)$(CHKERFD):
	@mkdir -p $@

$(OBJSFD)$(PUSHSWAPFD):
	@mkdir -p $@

$(OBJSFD)$(COREFD):
	@mkdir -p $@

# Linking and binaries
$(NAME): $(OBJSFD)$(CHKERFD) $(CHKER_OBJ) $(OBJSFD)$(COREFD) $(CORE_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(CHKER_OBJ) $(CORE_OBJ) $(LIBFT) -o $(NAME)

$(NAME2): $(OBJSFD)$(PUSHSWAPFD) $(PUSHSWAP_OBJ) $(OBJSFD)$(COREFD) $(CORE_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSHSWAP_OBJ) $(CORE_OBJ) $(LIBFT) -o $(NAME2)

# Objects compilation
$(OBJSFD)$(CHKERFD)%.o: $(SRCSFD)$(CHKERFD)%.c
	$(CC) $(INCLUDES) -c $< -o $@

$(OBJSFD)$(PUSHSWAPFD)%.o: $(SRCSFD)$(PUSHSWAPFD)%.c
	$(CC) $(INCLUDES) -c $< -o $@

$(OBJSFD)$(COREFD)%.o: $(SRCSFD)$(COREFD)%.c
	$(CC) $(INCLUDES) -c $< -o $@

# Utilities
clean:
	@rm -rf $(OBJSFD)
	@echo "$(RED)Remove $(OBJSFD)$(NONE)"
	@make -C ./libft clean 1>/dev/null

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@echo "$(RED)Remove $(NAME) $(NAME2)$(NONE)"
	@make -C ./libft fclean 1>/dev/null

re: fclean all

.PHONY: libft project all clean fclean re
