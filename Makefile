# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 12:02:51 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/11/01 17:02:38 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC	= $(addprefix src/, main.c image.c keyboard.c put_line.c raycast.c tools.c board_parse.c textures.c test_error.c tools_2.c)

OBJ = $(SRC:.c=.o)

CC	=  gcc
CFLAGS	=  -Wall -Wextra -Werror

MLX_LNK	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

FT		= ./Libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./Libft
FT_LNK	= -L ./Libft -l ft

SCRDIR 	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(FT_LIB) $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		make -C $(FT)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME) $(CFLAGS)

clean:
		rm -rf $(OBJ)
		make -C $(FT) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(FT) fclean

re: fclean all
