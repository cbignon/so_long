# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 11:29:57 by cbignon           #+#    #+#              #
#    Updated: 2021/10/28 12:03:10 by cbignon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft

SOURCES=	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isdigitstr.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strnstr.c \
			*ft_strchr.c \
			*ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_atoi.c \
			ft_strdup.c \
			*ft_calloc.c \
			*ft_substr.c \
			*ft_strjoin.c \
			*ft_strtrim.c \
			**ft_split.c \
			*ft_itoa.c \
			*ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_pow.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			*ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			*ft_lstmap.c \
			ft_strclen.c \
			free_str.c \
			try_to_malloc.c \
			get_next_line.c \

CFLAGS= -Wall -Werror -Wextra

CC= clang

.c.o : 
	$(CC) $(CFLAGS) -c $<

OBJETS= $(SOURCES:.c=.o)

$(NAME) : $(OBJETS)
	ar -rcs $(NAME).a $(OBJETS)

all : $(NAME)

so : $(OBJETS)
	$(CC) -o $(NAME).so -shared $(OBJETS)

clean :
	rm -f $(OBJETS)

fclean : clean
	rm -f $(NAME).a
	rm -f $(NAME).so

re : fclean all