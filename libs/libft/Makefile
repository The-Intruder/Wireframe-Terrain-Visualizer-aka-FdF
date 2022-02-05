# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:44:02 by mnaimi            #+#    #+#              #
#    Updated: 2021/11/16 12:15:14 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

FLAGS := -Wall -Wextra -Werror 

SRCS_M := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c

SRCS_B := ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
	ft_lstnew.c ft_lstsize.c

OBJS_M := $(SRCS_M:%.c=%.o)

OBJS_B := $(SRCS_B:%.c=%.o)

NAME := libft.a

.PHONY: all clean fclean re bonus compile

all: $(OBJS_M) $(NAME)

bonus: $(OBJS_B) all
	@echo "\nMaking Object file from $< ..."
	@ar rcs $(NAME) $(OBJS_M) $(OBJS_B)

compile: bonus main.c
	@echo "\nCompiling the main.c file ..."
	@$(CC) $(FLAGS) main.c -L. -lft

%.o: %.c
	@echo "\nMaking Object file from $< ..."	
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS_M) libft.h
	@echo "\nMaking archive file $(NAME) ..."
	@ar rcs $(NAME) $(OBJS_M)

clean:
	@echo "\nCleaning up Object Files ..."
	@rm -f *.o

fclean: clean
	@echo "\nCleaning up libft.a ..."
	@rm -f $(NAME)

re: fclean all
