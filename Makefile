# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 13:12:52 by hyap              #+#    #+#              #
#    Updated: 2021/05/24 22:08:27 by hyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COMP = gcc -Wall -Wextra -Werror

INCL = libft.h

PART_1-2 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strstr_bonus.c ft_numlen_bonus.c ft_isspace_bonus.c

OBJ_1-2 = $(PART_1-2:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS = $(BONUS:.c=.o)

.c.o:
	$(COMP) -include $(INCL) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_1-2)
	ar rc $(NAME) $(OBJ_1-2) $(INCL)

clean:
	rm -f $(OBJ_1-2) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

bonus: $(OBJ_1-2) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS) ${OBJ_1-2} $(INCL)

.PHONY: all clean fclean re bonus
