NAME 	=	ft_nm
HEAD	=	$(shell find includes -name '*.h' -type f)
SRC 	=	$(shell find $(DSRC) -name '*.c' -type f)
DOBJ 	=	objs
DSRC 	=	srcs
LIB 	=	-L ../libft/ -lft
INC 	=	-I includes/ -I ../libft/includes/
CC 		=	llvm-gcc $(INC)
# CFLAGS 	=	-Wall -Werror -Wextra
SDIR	=	$(shell find $(DSRC) -type d)
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))
OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))

all: $(NAME)
	
$(NAME): $(OBJ) $(HEAD)
	@make -C ../libft/ > /dev/null 2>&1
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(DOBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31;1m$(NAME) removes!\033[0m"

re: fclean all

.PHONY: re all clean fclean
