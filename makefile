# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 15:32:58 by aneekhra          #+#    #+#              #
#    Updated: 2024/03/19 18:43:47 by aneekhra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = check_input.c push_swap.c free.c index.c \
		push.c rev_rotate.c rotate.c sort.c string_utils.c  \
		stack_utils.c stack.c swap.c utils.c \

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME}

${NAME} : ${OBJ}
		@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
		@echo "Compilation went succesfully ✅✅✅✅"

$(OBJDIR)%.o:%.c
		@mkdir -p $(OBJDIR)
		@$(CC) $(CFLAGS) -c $< -o $@
		
clean:
		@rm -rf ${OBJDIR}

fclean: clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
