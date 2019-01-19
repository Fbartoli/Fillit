# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 19:36:27 by ftrujill          #+#    #+#              #
#    Updated: 2019/01/19 02:14:24 by flbartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			libft.a

CFLAGS = 		-Wall -Wextra -Werror

SRC =			ft_index_rev.c\
ft_max_int.c\
ft_min_int.c\
ft_max.c\
ft_min.c\
ft_lstdelnext.c\
ft_realloc.c\
ft_memindex.c\
ft_memjoin_alloc.c\
ft_memjoin_allocf.c\
ft_atoi.c\
ft_bzero.c\
ft_index.c\
ft_index_uc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_lstprt.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memlap_fwd.c\
ft_memmove.c\
ft_memnlap_fwd.c\
ft_memset.c\
ft_print_params.c\
ft_print_tab.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putnstr.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_strrev.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\

OBJ =			$(SRC:.c=.o)

all: 			$(NAME) $(SRC)

$(NAME):		$(OBJ)
				@ar rc libft.a $(OBJ)
				@ranlib libft.a

clean:
				@rm -f $(OBJ)

fclean: 		clean
				@rm -f $(NAME)

re:				fclean all