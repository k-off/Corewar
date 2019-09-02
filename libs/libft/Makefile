#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/13 11:11:47 by pacovali      #+#    #+#                  #
#    Updated: 2019/01/19 19:16:26 by pacovali      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = ./mem/ft_bzero.c ./mem/ft_memalloc.c ./mem/ft_memccpy.c  \
./mem/ft_memchr.c ./mem/ft_memcmp.c ./mem/ft_memcpy.c ./mem/ft_memdel.c \
./mem/ft_memdup.c ./mem/ft_memmove.c ./mem/ft_memmove.c ./mem/ft_memmove.c \
./mem/ft_memset.c \
./str/ft_stracat.c ./str/ft_strcapitalize.c ./str/ft_strcasecmp.c \
./str/ft_strcasestr.c ./str/ft_strcat.c ./str/ft_strchr.c ./str/ft_strclr.c \
./str/ft_strcmp.c ./str/ft_strcntc.c ./str/ft_strcntw.c ./str/ft_strcpy.c \
./str/ft_strdel.c ./str/ft_strdup.c ./str/ft_strequ.c ./str/ft_striter.c \
./str/ft_striteri.c ./str/ft_strjoin.c ./str/ft_strlcat.c ./str/ft_strlcpy.c \
./str/ft_strlen.c ./str/ft_strlowcase.c ./str/ft_strmap.c ./str/ft_strmapi.c \
./str/ft_strncasecmp.c ./str/ft_strncat.c ./str/ft_strncmp.c \
./str/ft_strncpy.c ./str/ft_strndup.c ./str/ft_strnequ.c ./str/ft_strnew.c \
./str/ft_strnstr.c ./str/ft_strrchr.c ./str/ft_strsplit.c ./str/ft_strstr.c \
./str/ft_strsub.c ./str/ft_strtrim.c ./str/ft_strupcase.c ./str/ft_tolower.c \
./str/ft_toupper.c ./str/ft_strrev.c ./str/ft_strsplit_whitespace.c \
./chck/ft_isalnum.c ./chck/ft_isalpha.c ./chck/ft_isascii.c \
./chck/ft_isblanc.c ./chck/ft_iscntrl.c ./chck/ft_isdigit.c \
./chck/ft_isgraph.c ./chck/ft_islower.c ./chck/ft_isprint.c \
./chck/ft_isspace.c ./chck/ft_isupper.c ./chck/ft_isxdigit.c \
./chck/ft_str_is_alpha.c ./chck/ft_str_is_lowercase.c \
./chck/ft_str_is_numeric.c ./chck/ft_str_is_printable.c \
./chck/ft_str_is_uppercase.c \
./aito/ft_atoi.c ./aito/ft_itoa_base.c ./aito/ft_itoa.c ./aito/ft_ldtoa.c \
./aito/ft_strtold10.c ./aito/ft_strtoll.c ./aito/ft_lltoa_base.c \
./aito/ft_ulltoa_base.c ./aito/ft_ldtoa_utils.c \
./lst/ft_lstadd.c ./lst/ft_lstappend.c ./lst/ft_lstdel.c \
./lst/ft_lstdelone.c ./lst/ft_lstiter.c ./lst/ft_lstmap.c ./lst/ft_lstnew.c \
./inpout/ft_putchar_fd.c ./inpout/ft_putchar.c ./inpout/ft_putendl_fd.c \
./inpout/ft_putendl.c ./inpout/ft_putnbr_fd.c ./inpout/ft_putnbr.c \
./inpout/ft_putnstr_fd.c ./inpout/ft_putnstr.c ./inpout/ft_putstr_fd.c \
./inpout/ft_putstr.c ./inpout/ft_readfile_fd.c ./inpout/ft_readfile_name.c \
./inpout/get_next_line.c \
./printf/conv_handlers.c ./printf/conversions.c ./printf/ft_printf.c \
./printf/get_data.c ./printf/get_utils.c ./printf/printf_utils.c \
./printf/conv_utils.c ./printf/sprintf_utils.c ./printf/ft_sprintf.c \
./printf/ft_printf_fd.c

MKOBJ = @gcc -c -Wall -Wextra -Werror
HDRS = -I .
OBJS = ft_bzero.o ft_memalloc.o ft_memccpy.o  \
ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o \
ft_memdup.o ft_memmove.o ft_memmove.o ft_memmove.o \
ft_memset.o \
ft_stracat.o ft_strcapitalize.o ft_strcasecmp.o \
ft_strcasestr.o ft_strcat.o ft_strchr.o ft_strclr.o \
ft_strcmp.o ft_strcntc.o ft_strcntw.o ft_strcpy.o \
ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o \
ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o \
ft_strlen.o ft_strlowcase.o ft_strmap.o ft_strmapi.o \
ft_strncasecmp.o ft_strncat.o ft_strncmp.o \
ft_strncpy.o ft_strndup.o ft_strnequ.o ft_strnew.o \
ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o \
ft_strsub.o ft_strtrim.o ft_strupcase.o ft_tolower.o \
ft_toupper.o ft_strrev.o ft_strsplit_whitespace.o \
ft_isalnum.o ft_isalpha.o ft_isascii.o \
ft_isblanc.o ft_iscntrl.o ft_isdigit.o \
ft_isgraph.o ft_islower.o ft_isprint.o \
ft_isspace.o ft_isupper.o ft_isxdigit.o \
ft_str_is_alpha.o ft_str_is_lowercase.o \
ft_str_is_numeric.o ft_str_is_printable.o \
ft_str_is_uppercase.o \
ft_atoi.o ft_itoa_base.o ft_itoa.o ft_ldtoa.o \
ft_strtold10.o ft_strtoll.o ft_lltoa_base.o \
ft_ulltoa_base.o ft_ldtoa_utils.o \
ft_lstadd.o ft_lstappend.o ft_lstdel.o ft_lstdelone.o \
ft_lstiter.o ft_lstmap.o ft_lstnew.o \
ft_putchar_fd.o ft_putchar.o ft_putendl_fd.o \
ft_putendl.o ft_putnbr_fd.o ft_putnbr.o \
ft_putnstr_fd.o ft_putnstr.o ft_putstr_fd.o \
ft_putstr.o ft_readfile_fd.o ft_readfile_name.o \
get_next_line.o \
conv_handlers.o conversions.o ft_printf.o \
get_data.o get_utils.o printf_utils.o \
conv_utils.o sprintf_utils.o ft_sprintf.o ft_printf_fd.o


MKLIB = @ar -rc

all: $(NAME)
$(NAME):
	$(MKOBJ) $(SRCS) $(HDRS)
	$(MKLIB) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) *~

fclean: clean
	@rm -f $(NAME)

re: fclean all