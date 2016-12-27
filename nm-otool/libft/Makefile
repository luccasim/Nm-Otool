#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/11 15:48:23 by luccasim          #+#    #+#              #
#    Updated: 2016/11/14 17:21:19 by luccasim         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	llvm-gcc $(CFLAGS)
CFLAGS	=	-Wall -Werror -Wextra
INC		=	-I includes/ -I minilibx_macos/
HEAD	=	$(shell find includes -name '*.h' -type f)
MLX		=	-L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
SRC		=	$(shell find srcs -name '*.c' -type f)
OBJ		=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
SDIR	=	$(shell find srcs -type d)
ODIR	=	$(addprefix $(DOBJ)/,$(SDIR))
DOBJ	=	objs
NAME	=	libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) > /dev/null 2>&1
	@ranlib $(NAME)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR) > /dev/null 2>&1
	@$(CC) $(INC) -c $< -o $@

test: $(NAME) main.c $(HEAD)
	llvm-gcc -o test main.c -L . -lft $(MLX) -I includes

clean:
	@/bin/rm -rf $(DOBJ) > /dev/null 2>&1

fclean: clean
	@/bin/rm -rf $(NAME) > /dev/null 2>&1
	@echo "\033[31;1m$(NAME) removes!\033[0m"

norme: $(SRC)
	norminette srcs/*/*.c
	norminette includes/*.h

re: fclean all

.PHONY: clean fclean re all
