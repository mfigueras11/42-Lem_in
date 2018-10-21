# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 10:12:04 by mfiguera          #+#    #+#              #
#    Updated: 2018/03/30 14:36:17 by mfiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf1.c ft_printf2.c ft_printf_d.c ft_printf_o.c ft_printf_u.c ft_printf_x.c ft_printf_c.c ft_printf_pc.c ft_printf_s.c ft_printf_p.c
OBJ = $(SOURCES:.c=.o)  
INCLUDES = ft_printf.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SOURCES) -I $(INCLUDES)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make
