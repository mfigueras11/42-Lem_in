# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 17:16:58 by mfiguera          #+#    #+#              #
#    Updated: 2018/05/07 14:51:33 by mfiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strnjoin.c ft_atoiptr.c ft_sttoa.c ft_itoabase.c ft_utoa.c ft_toupperstr.c ft_mbstr.c ft_strjoinfree.c ft_strrev.c ft_swap.c ft_get_next_line.c ft_wordcount.c ft_isnumstr.c
OFILES = $(CFILES:.c=.o) Printf/ft_printf1.o Printf/ft_printf2.o Printf/ft_printf_d.o Printf/ft_printf_x.o Printf/ft_printf_o.o Printf/ft_printf_s.o Printf/ft_printf_c.o Printf/ft_printf_pc.o Printf/ft_printf_p.o Printf/ft_printf_u.o
NAME = libft.a

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(CFILES) -I libft.h
	@cd Printf && make
	@ar rc libft.a $(OFILES)

all: $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f libft.a

re: fclean
	@make
