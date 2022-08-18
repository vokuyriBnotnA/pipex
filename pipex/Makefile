# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 20:52:38 by klemongr          #+#    #+#              #
#    Updated: 2022/01/25 18:46:23 by klemongr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror

LIST =	main.c			\
		ft_split.c		\
		ft_strjoin.c	\
		ft_strlen.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		get_next_line.c \
		pipex.c			\
		aprove_file.c

OBJSFD = temporary

OBJ = $(addprefix $(OBJSFD)/,$(LIST:.c=.o))

all : $(NAME)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	gcc -g $(OBJ) -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
