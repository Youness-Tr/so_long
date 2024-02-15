# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 16:07:18 by ytarhoua          #+#    #+#              #
#    Updated: 2024/02/15 09:52:15 by ytarhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC  =  check_map.c utils.c drawing.c error.c floodfill.c ft_itoa.c ft_split.c libft_funcs.c get_next_line.c get_next_line_utils.c images.c moving.c so_long.c
OBJ = $(SRC:.c=.o)
CC	= cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		${CC} $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)