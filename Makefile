# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:28:04 by lgiacalo          #+#    #+#              #
#    Updated: 2019/03/22 20:18:14 by lgiacalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM			= ft_nm


################################################################################


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude -Ilibft/include
OPT			=

COLOR		= \033[31m
FINCOLOR	= \033[0m

SPY			=


################################################################################


SRC_PATH	= src
INC_PATH	= include
OBJ_PATH	= obj


SRC_NM		= main.c ft_option.c print_info.c\
				env.c verif.c usage.c error.c\
				ft_file.c ft_type_file.c ft_type_cpu.c\
				record_struct.c swap.c copy.c\
				fatbinary.c archive_static.c\
				load_command.c nlist.c list_line.c tri.c\
				function_nbr.c function_str.c

INC_NM		= ft_nm_otool.h ft_nm.h
OBJ_NM		= $(SRC_NM:.c=.o)


################################################################################


SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NM))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NM))
INC = $(addprefix $(INC_PATH)/,$(INC_NM))

LIB	= libft/libft.a

################################################################################

ifeq ($(option), debug)
	OPT += -g
endif
ifeq ($(option), alloc)
	OPT += -g -fsanitize=address
endif
ifeq ($(option), opti)
	OPT += -O3
endif
ifeq ($(option), dev)
	CFLAGS = -g
endif

export OPT

################################################################################

all: lib $(NM)


$(OBJ_PATH):
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) $(LIB) Makefile
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


$(LIB):
	$(SPY)make -C libft/

lib :
	$(SPY)make -C libft/


$(NM): $(LIB) $(OBJ_PATH) $(OBJ)
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -o $(NM) $(OBJ) $(LIB)
	$(SPY)echo "$(COLOR)$(NM)\t\t\t[OK]$(FINCOLOR)"


clean:
	$(SPY)make clean -C libft/
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)$(NM)\t\t\tSuppression *.o$(FINCOLOR)"


fclean: clean
	$(SPY)make fclean -C libft/
	$(SPY)/bin/rm -rf $(NM)
	$(SPY)echo "$(COLOR)$(NM)\t\t\tSuppression $(NM)$(FINCOLOR)"


re: fclean all


norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : $(NM)\n$(FINCOLOR)"
	$(SPY)norminette $(SRC)
	$(SPY)norminette $(INC)


.PHONY : all clean fclean re norme

################################################################################
