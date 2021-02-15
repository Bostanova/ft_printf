# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 20:37:59 by eerika            #+#    #+#              #
#    Updated: 2021/02/15 13:30:14 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

FLAGS = gcc -Wall -Wextra -Werror $(LIBFT_H) -c -o

LIBFT_H = -I libft/
PRINTF_H = -I srcs/

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = libft/

SRC = ft_printf.c \
		ft_conversions.c \
		char_string.c\
		printer.c \
		pointer_percent.c \
		int.c \
		unsignint.c \
		hexa.c \
		ft_flags.c \

CFIND = $(SRC:%=$(SRC_DIR)%)

OBJS = $(SRC:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
				@make -C $(LIB_DIR)
				@cp $(LIB_DIR)$(LIBFT) .
				@mv $(LIBFT) $(NAME)
				ar -src $(NAME) $(addprefix $(OBJ_DIR), $(OBJS))
$(OBJ): $(CFIND)
				@$(MAKE) $(OBJS)
$(OBJS):
			@$(FLAGS) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
clean:
				@make clean -C $(LIB_DIR)
				/bin/rm -rf $(OBJ_DIR)

fclean:			clean
				@make fclean -C $(LIB_DIR)
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re