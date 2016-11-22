NAME		= 	$(NAME1) $(NAME2)
NAME1 		=	ft_nm
NAME2		=	ft_otool
DEP_NM		=	nm/ft_nm
DEP_OTOOL	=	otool/ft_otool

all: $(NAME)

$(NAME1): $(DEP_NM)
	@cp nm/$(NAME1) .

$(NAME2): $(DEP_OTOOL)
	@cp otool/$(NAME2) .

$(DEP_NM):
	@make -C nm/

$(DEP_OTOOL):
	@make -C otool/

clean:
	@make -C nm/ clean
	@make -C otool/ clean

fclean: clean
	@make -C nm/ fclean
	@make -C otool/ fclean
	@/bin/rm -rf $(NAME1)
	@/bin/rm -rf $(NAME2)

re: fclean all

.PHONY: re all clean fclean
