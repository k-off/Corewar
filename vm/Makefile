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
SRCS = battle.c battle2.c carriage_command_hub.c \
carriage_support3.c carriages_support.c carriages_support2.c carriages.c \
error_handling.c extract_data.c extract_warrior_data.c main.c print.c \
provide_unique_id.c save_setup.c save.c utils.c utils2.c utils3.c utils4.c \
visual_carriage_info.c visual_debug.c visual_events.c visual_functions.c \
visual_history.c visual_image_handle.c \
operations/add.c operations/aff.c operations/and.c operations/and2.c \
operations/fork.c operations/jump.c operations/ld.c operations/ldi.c \
operations/ldi2.c operations/lfork.c operations/live.c operations/lld.c \
operations/lldi.c operations/lldi2.c operations/or.c operations/or2.c \
operations/st.c operations/st2.c operations/sti.c operations/sti2.c \
operations/sub.c operations/xor.c operations/xor2.c operations/zjmp.c
MKOBJ = @gcc -c
FLAGS = -Wall -Wextra -Werror
HDRS = -I ../includes/assembler.h ../includes/disassembler.h \
../includes/ft_printf.h ../includes/header.h ../includes/ldtoa.h \
../includes/libft.h ../includes/mlx.h ../includes/op.h ../includes/visual.h
OBJS = battle.o battle2.o carriage_command_hub.o \
carriage_support3.o carriages_support.o carriages_support2.o carriages.o \
error_handling.o extract_data.o extract_warrior_data.o main.o print.o \
provide_unique_id.o save_setup.o save.o utils.o utils2.o utils3.o utils4.o \
visual_carriage_info.o visual_debug.o visual_events.o visual_functions.o \
visual_history.o visual_image_handle.o \
add.o aff.o and.o and2.o \
fork.o jump.o ld.o ldi.o \
ldi2.o lfork.o live.o lld.o \
lldi.o lldi2.o or.o or2.o \
st.o st2.o sti.o sti2.o \
sub.o xor.o xor2.o zjmp.o
MLX = ../libs/libmlx/libmlx.a -framework OpenGL -framework AppKit
LFT = ../libs/libft/libft.a
MKEXE = gcc -o $(NAME)

all: $(NAME)
$(NAME):
	@$(MKOBJ) $(FLAGS) $(HDRS) $(SRCS)
	@$(MKEXE) $(MLX) $(LFT) $(OBJS) $(LFT) $(MLX)

clean:
	@rm -f $(OBJS) *~

fclean: clean
	@rm -f $(NAME)

re: fclean all
