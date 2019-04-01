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

OTOOL		= ft_otool

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


SRC_NM		= main_nm.c ft_option.c print_info.c\
				env.c verif.c usage.c error.c\
				ft_file.c ft_type_file.c\
				record_struct.c swap.c copy.c\
				fatbinary.c archive_static.c\
				load_command.c nlist.c list_line.c tri.c\
				function_nbr.c function_str.c

INC_NM		= ft_nm_otool.h ft_nm.h
OBJ_NM		= $(SRC_NM:.c=.o)


SRC_OTOOL	= main_otool.c

INC_OTOOL	= ft_otool.h

OBJ_OTOOL	= $(SRC_OTOOL:.c=.o)

################################################################################

SRC_N	= $(addprefix $(SRC_PATH)/,$(SRC_NM))
OBJ_N	= $(addprefix $(OBJ_PATH)/,$(OBJ_NM))
INC_N = $(addprefix $(INC_PATH)/,$(INC_NM))

SRC_O	= $(addprefix $(SRC_PATH)/,$(SRC_OTOOL))
OBJ_O	= $(addprefix $(OBJ_PATH)/,$(OBJ_OTOOL))
INC_O = $(addprefix $(INC_PATH)/,$(INC_OTOOL))

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

all: lib $(NM) $(OTOOL)

$(OBJ_PATH):
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_N) $(INC_O) $(LIB) Makefile
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIB):
	$(SPY)make -C libft/

lib :
	$(SPY)make -C libft/


$(NM): $(LIB) $(OBJ_PATH) $(OBJ_N)
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -o $(NM) $(OBJ_N) $(LIB)
	$(SPY)echo "$(COLOR)$(NM)\t\t\t[OK]$(FINCOLOR)"

$(OTOOL): $(LIB) $(OBJ_PATH) $(OBJ_O)
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -o $(OTOOL) $(OBJ_O) $(LIB)
	$(SPY)echo "$(COLOR)$(OTOOL)\t\t\t[OK]$(FINCOLOR)"

clean:
	$(SPY)make clean -C libft/
	$(SPY)/bin/rm -rf $(OBJ_N)
	$(SPY)/bin/rm -rf $(OBJ_O)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)$(NM)\t\t\tSuppression *.o$(FINCOLOR)"
	$(SPY)echo "$(COLOR)$(OTOOL)\t\tSuppression *.o$(FINCOLOR)"

fclean: clean
	$(SPY)make fclean -C libft/
	$(SPY)/bin/rm -rf $(NM)
	$(SPY)/bin/rm -rf $(OTOOL)
	$(SPY)echo "$(COLOR)$(NM)\t\t\tSuppression $(NM)$(FINCOLOR)"
	$(SPY)echo "$(COLOR)$(OTOOL)\t\tSuppression $(OTOOL)$(FINCOLOR)"

re: fclean all

norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : $(NM) - $(OTOOL) \n$(FINCOLOR)"
	$(SPY)norminette $(SRC_N)
	$(SPY)norminette $(SRC_O)
	$(SPY)norminette $(INC_N)
	$(SPY)norminette $(INC_O)


.PHONY : all clean fclean re norme

################################################################################
