NAME	= 	$(NAME1) #$(NAME2)
NAME1 	=	a.out #ft_nm
NAME2	=	ft_otool

DSRC_NM =	srcs/nm
DOBJ_NM =	$(DOBJ)/nm
SRC_NM 	=	$(shell find $(DSRC_NM) -name '*.c' -type f)
SDIR_NM	=	$(shell find $(DSRC_NM) -type d)
OBJ_NM 	=	$(patsubst %.c, $(DOBJ_NM)/%.o, $(SRC_NM))
ODIR_NM	=	$(addprefix $(DOBJ_NM)/, $(SDIR_NM))

DSRC_OT =	srcs/otool
DOBJ_OT =	$(DOBJ)/otool
SRC_OT 	=	$(shell find $(DSRC_OT) -name '*.c' -type f)
SDIR_OT	=	$(shell find $(DSRC_OT) -type d)
OBJ_OT 	=	$(patsubst %.c, $(DOBJ_OT)/%.o, $(SRC_OT))
ODIR_OT	=	$(addprefix $(DOBJ_OT)/, $(SDIR_OT))

DOBJ 	= 	objs
LIB 	=	-L libft/ -lft
INC 	=	-I includes/ -I libft/includes/
CC 		=	llvm-gcc
CFLAGS 	=	-Wall -Werror -Wextra $(INC)

all: $(NAME)

$(NAME1): $(OBJ_NM)
	@make -C libft/
	@$(CC) -o $(NAME1) $(OBJ_NM) $(LIB)
	@echo "\033[32;1m$(NAME1) created successfully!\033[0m"

$(NAME2): $(OBJ_OT)
	@make -C libft/
	@$(CC) -o $(NAME2) $(OBJ_OT) $(LIB)
	@echo "\033[32;1m$(NAME2) created successfully!\033[0m"

$(DOBJ_NM)/%.o: %.c
	@mkdir -p $(ODIR_NM)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DOBJ_OT)/%.o: %.c
	@mkdir -p $(ODIR_OT)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(DOBJ)

fclean: clean
	@/bin/rm -rf $(NAME1)
	@echo "\033[31;1m$(NAME1) removes!\033[0m"
	@/bin/rm -rf $(NAME2)
	@echo "\033[31;1m$(NAME2) removes!\033[0m"	

re: fclean all

.PHONY: re all clean fclean
