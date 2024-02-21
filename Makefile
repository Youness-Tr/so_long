# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 16:07:18 by ytarhoua          #+#    #+#              #
#    Updated: 2024/02/21 12:15:22 by ytarhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_b

SRC  =  check_map.c utils.c drawing.c error.c floodfill.c ft_itoa.c ft_split.c libft_funcs.c get_next_line.c get_next_line_utils.c images.c moving.c so_long.c
SRC_B = ./bonus/check_map_bonus.c ./bonus/utils_bonus.c ./bonus/drawing_bonus.c ./bonus/error_bonus.c ./bonus/floodfill_bonus.c ./bonus/ft_itoa_bonus.c ./bonus/ft_split_bonus.c ./bonus/libft_funcs_bonus.c 
SRC_B +=./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/images_bonus.c ./bonus/moving_bonus.c ./bonus/so_long_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
CC	= cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		${CC} $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B)
		${CC} $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ_B) -o $(NAME_B)

clean :
		rm -rf $(OBJ) $(OBJ_B)

fclean : clean
		rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) $(OBJ_B)