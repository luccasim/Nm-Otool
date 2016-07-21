#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/11 15:48:23 by luccasim          #+#    #+#              #
#    Updated: 2016/03/29 17:04:22 by luccasim         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	llvm-gcc $(CFLAGS)
CFLAGS	=	-Wall -Werror -Wextra $(INC)
INC		=	-I includes/
SRC		=	$(shell find srcs -name '*.c' -type f)
OBJ		=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
SDIR	=	$(shell find srcs -type d)
ODIR	=	$(addprefix $(DOBJ)/,$(SDIR))
DOBJ	=	objs
NAME	=	libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	$(CC) -c $< -o $@

clean:
	@/bin/rm -rf $(DOBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31;1m$(NAME) removes!\033[0m"

norme: $(SRC)
	norminette srcs/*/*.c
	norminette includes/*.h

re: fclean all

.PHONY: clean fclean re all
