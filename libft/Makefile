#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/19 22:14:00 by lgiacalo          #+#    #+#             *#
#*   Updated: 2017/07/23 19:49:00 by lgiacalo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME		= libft.a


################################################################################


CC			= gcc  
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude

COLOR		= \033[36m
FINCOLOR	= \033[0m

SPY			= @

################################################################################


SRC_PATH	= src

INC_PATH	= include

OBJ_PATH	= obj

SRC_NAME	= ft_fdprintf.c ft_strnsplit.c ft_atolli.c ft_arraydel.c ft_arraylen.c\
			ft_isnumber.c ft_arrayprint.c ft_printf.c ft_flags_init.c ft_flags.c\
			ft_conv_xuo.c ft_conv_s.c ft_conv_p.c ft_conv_di.c ft_conv_c.c ft_conv_b.c\
			\
			ft_wstrlen.c ft_wstrlen_o.c ft_wcharlen_o.c\
			ft_putpnbr_base_nb.c ft_putpnbr_nb.c ft_pitoa_base.c ft_len_pnumbers_base.c\
			ft_atoi_base.c ft_itoa_base.c ft_len_numbers_base.c ft_verif_base.c\
			ft_putnbr_base_fd_nb.c ft_putnbr_base_nb.c ft_putnbr_base_fd.c ft_putnbr_base.c\
			ft_putwstr_nb.c ft_putwstr_fd_nb.c ft_putwstr.c ft_putwstr_fd.c\
			ft_putwchar.c ft_putwchar_fd.c ft_putnbr_fd_nb.c ft_putnbr_nb.c\
			ft_putstr_fd_nb.c ft_putendl_nb.c ft_putendl_fd_nb.c\
			ft_lstrev.c ft_strstrchr.c ft_strstrchr_ind.c ft_chrstr_ind.c ft_strchr_ind.c\
			get_next_line.c ft_strdigit.c ft_lstat.c ft_lstend.c ft_lstsize.c\
			ft_strrev.c ft_swap.c ft_power.c ft_sqrt.c ft_is_prime.c\
			ft_find_next_prime.c ft_strupcase.c ft_strlowcase.c ft_strcapitalize.c\
			ft_putstr_fd.c ft_atoi.c ft_strcat.c ft_bzero.c ft_strchr.c ft_isalnum.c\
			ft_strclr.c ft_isalpha.c ft_strcmp.c ft_isascii.c ft_strcpy.c ft_isdigit.c\
			ft_strdel.c ft_isprint.c ft_strdup.c ft_itoa.c ft_strequ.c ft_len_numbers.c\
			ft_lstadd.c ft_striteri.c ft_lstdel.c ft_strjoin.c ft_lstdelone.c ft_strlcat.c\
			ft_lstiter.c ft_strlen.c ft_lstmap.c ft_strmap.c ft_lstnew.c ft_lstadd_end.c\
			ft_strmapi.c ft_memalloc.c ft_strncat.c ft_memccpy.c ft_strncmp.c ft_memchr.c\
			ft_strncpy.c ft_memcmp.c ft_strnequ.c ft_memcpy.c ft_strnew.c ft_memdel.c\
			ft_strnstr.c ft_memmove.c ft_strrchr.c ft_memset.c ft_strsplit.c\
			ft_nbwords.c ft_poswords.c ft_putchar.c ft_strstr.c ft_putchar_fd.c ft_strsub.c\
			ft_striter.c ft_putendl.c ft_strtrim.c ft_putendl_fd.c ft_tolower.c ft_putnbr.c\
			ft_toupper.c ft_putstr.c ft_putstr_fd.c ft_putnbr_fd.c

INC_NAME	= flags.h ft_printf.h libft.h

OBJ_NAME	= $(SRC_NAME:.c=.o)


################################################################################


SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
INC			= $(addprefix $(INC_PATH)/,$(INC_NAME))
OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


################################################################################


all: $(NAME)

$(OBJ_PATH): 
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 
	@printf "\e[38;5;208m▒\e[0m"

$(NAME): $(OBJ_PATH) $(OBJ)
	$(SPY)ar rc $(NAME) $(OBJ)
	$(SPY)ranlib $(NAME)
	@printf "\n"

clean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)LIBFT\t\t\tSuppression *.o$(FINCOLOR)"


fclean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)/bin/rm -rf $(NAME)
	$(SPY)echo "$(COLOR)LIBFT\t\t\tSuppression libft.a$(FINCOLOR)"


re: fclean all


norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : LIBFT\n$(FINCOLOR)"
	$(SPY)norminette $(SRC)
	$(SPY)norminette include/*.h


.PHONY : all clean fclean re norme

################################################################################
