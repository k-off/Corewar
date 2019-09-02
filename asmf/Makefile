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
SRCS = check_data.c get_arguments.c get_instructions.c get_labels.c \
get_name_and_comment.c main.c set_arguments.c utils.c write_data.c
MKOBJ = @gcc -c -Wall -Wextra -Werror
HDRS = -I ../includes
OBJS = check_data.o get_arguments.o get_instructions.o get_labels.o \
get_name_and_comment.o main.o set_arguments.o utils.o write_data.o
LFT = -L ../libs/libft -lft
MKEXE = @gcc -o

all: $(NAME)
$(NAME):
	$(MKOBJ) $(SRCS) $(HDRS)
	$(MKEXE) $(NAME) $(OBJS) $(LFT)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
