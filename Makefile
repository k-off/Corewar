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

NAME = corewar

all: $(NAME)
$(NAME):
	@make -C libs/libft
	@make -C libs/libmlx
	@make -C asmf
	@make -C dasmf
	@make -C vm
	@mv ./asmf/asm asm
	@mv ./dasmf/dasm dasm
	@mv ./vm/corewar corewar

clean:
	@make -C libs/libft clean
	@make -C libs/libmlx clean
	@make -C asmf clean
	@make -C dasmf clean
	@make -C vm clean

fclean: clean
	@make -C libs/libft fclean
	@make -C libs/libmlx clean
	@make -C asmf fclean
	@make -C dasmf fclean
	@make -C vm fclean
	@rm -f asm
	@rm -f $(NAME)
	@rm -f dasm

re: fclean all
