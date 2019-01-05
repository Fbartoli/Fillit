# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 12:56:28 by flbartol          #+#    #+#              #
#    Updated: 2019/01/05 20:21:26 by flbartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fillit

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(SRC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fillit.h

SRC_NAME = aux.c check_tab.c display.c input.c main.c map.c recursive.c utils.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft
	@echo "$(OKC)FILLIT:\t\tFillit ready$(NOC)"
	@echo "======"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo -n =

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)
	@echo "$(WAC)FILLIT:\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FILLIT:\t\tRemoving fillit executable$(NOC)"

re: fclean all
