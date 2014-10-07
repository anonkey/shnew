# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.dep                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/03 14:36:54 by tseguier          #+#    #+#              #
#    Updated: 2014/10/04 18:20:08 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



HEADERS = headers/
SRCDIR = srcs/
CC = clang
ifeq ($(DEBUG), 1)
	CFLAGS = -Wall -Wextra -Werror -ggdb3
else
	CFLAGS = -Wall -Wextra -Werror
endif
LDFLAGS = rc
NAME = libft.a
SRC = ft_atoi.c \
ft_atoi_base.c \
ft_btree.c \
ft_btree_put.c \
ft_bzero.c \
ft_dynstradd.c \
ft_dynstrdel.c \
ft_dynstrflush.c \
ft_dynstrnew.c \
ft_dynstrput.c \
ft_getchar.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_ldcd_celldel.c \
ft_ldcd_cellnew.c \
ft_ldcdat.c \
ft_ldcddel.c \
ft_ldcddel_head.c \
ft_ldcddel_tail.c \
ft_ldcditer.c \
ft_ldcdnew.c \
ft_ldcdpop.c \
ft_ldcdpop_back.c \
ft_ldcdpop_front.c \
ft_ldcdpush_back.c \
ft_ldcdpush_front.c \
ft_ldcdpush_sorted.c \
ft_ldcdsize.c \
ft_ldcdsize_ref.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
ft_lsttotab.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memdup.c \
ft_memmove.c \
ft_memset.c \
ft_print_memory.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putdouble.c \
ft_putdouble_sci.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putldouble.c \
ft_putldouble_sci.c \
ft_putnbr.c \
ft_putnbr_base.c \
ft_putnbr_fd.c \
ft_putnbr_len.c \
ft_putnbr_ll.c \
ft_putnbr_oct.c \
ft_putnbr_ulen.c \
ft_putnbr_ull.c \
ft_putnbrhex.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_putstr_len.c \
ft_strcat.c \
ft_strchind.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strcsub.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchind.c \
ft_strrchr.c \
ft_strrev.c \
ft_strsepjoin.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtabcpy.c \
ft_strtabdel.c \
ft_strtabrealloc.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
get_next_line.c \
main.c \
printf/ft_printf.c \
printf/ft_printfn.c \
printf/ft_readarg.c \
printf/ft_readautom.c \
printf/ft_readchar.c \
printf/ft_readfloat.c \
printf/ft_readfloat_len.c \
printf/ft_readint.c \
printf/ft_readint_len.c \
printf/ft_readpoint.c \
printf/ft_readstr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(LDFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(HEADERS)

.PHONY: clean fclean all re $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
