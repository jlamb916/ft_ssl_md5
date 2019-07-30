# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 00:12:51 by jolam             #+#    #+#              #
#    Updated: 2019/04/30 16:47:04 by jolam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#

GCC = gcc

NAME = ft_ssl

FLAGS = -g -Wall -Werror -Wextra

LIBFT = libft

LIB = libft.a

SRCS =  main.c\
		parse.c\
		checks.c\
	   	md5.c\
	   	sha256.c\
	   	init.c\
		print_sha256.c\
		print_md5.c\
		helper.c\

OBJS = main.o\
	   parse.o\
	   checks.o\
	   md5.o\
	   sha256.o\
	   init.o\
	   print_sha256.o\
	   print_md5.o\
	   helper.o\

LIBFLAGS = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(GCC) $(FLAGS) -c $(SRCS) -I $(LIBFT)
	$(GCC) -o $(NAME) $(OBJS) $(LIBFLAGS)

clean:
	rm -f $(OBJS)
	make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIB)

re: fclean all
