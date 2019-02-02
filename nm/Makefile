#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/19 22:14:00 by lgiacalo          #+#    #+#             *#
#*   Updated: 2017/09/01 00:52:40 by lgiacalo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


################################################################################

NAME 		= ft_nm

################################################################################

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude -I ../include

COLOR		= \033[31m
FINCOLOR	= \033[0m
SPY			= @

################################################################################

SRC_PATH	=	src
INC_PATH	=	include
OBJ_PATH	=	obj

SRC_NAME	=	main.c env.c error.c\
				function_nbr.c function_str.c print_info.c\
				func1_libft.c

INC_NAME	=	ft_nm.h
OBJ_NAME	=	$(SRC_NAME:.c=.o)

################################################################################

SRC	= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC	= $(addprefix $(INC_PATH)/, $(INC_NAME))

################################################################################

ifeq ($(option), dev)
	CFLAGS = -g
endif

################################################################################

all: $(NAME)

$(OBJ_PATH):
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ_PATH) $(OBJ) Makefile
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME)
	$(SPY)echo "$(COLOR)$(NAME) \t\t\t[OK]$(FINCOLOR)"

clean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)Suppression *.o$(FINCOLOR)"

fclean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)Suppression *.o$(FINCOLOR)"
	$(SPY)/bin/rm -rf $(NAME)
	$(SPY)echo "$(COLOR)Suppression $(NAME)$(FINCOLOR)"

re: fclean all

norme:
	$(SPY)norminette $(SRC)
	$(SPY)norminette $(INC)


.PHONY : all clean fclean re norme

################################################################################
