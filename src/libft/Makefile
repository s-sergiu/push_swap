# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2022/10/23 23:29:48 by ssergiu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_strlen \
		ft_atoi \
		ft_calloc \
		ft_isdigit \
		ft_bzero \
		ft_strncmp \
		ft_strjoin \
		ft_split \
		ft_itoa \
		ft_putchar_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_strlcpy \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstadd_back \
		ft_lstsize \
		ft_lstlast \
		ft_lstdelone \
		ft_lstclear

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
