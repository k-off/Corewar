#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                  #
#    Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = asm

all: $(NAME)
$(NAME):
	@make -C libs/libft
	@make -C libs/libmlx
	@make -C asmf
	@mv ./asmf/$(NAME) $(NAME)

clean:
	@make -C libs/libft clean
	@make -C libs/libmlx clean
	@make -C asmf clean

fclean: clean
	@make -C libs/libft fclean
	@make -C libs/libmlx clean
	@make -C asmf fclean
	@rm -f $(NAME)

re: fclean all
