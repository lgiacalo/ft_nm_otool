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



OTOOL		= ft_otool
NM			= ft_nm

################################################################################

OPT			=
option		=

COLOR		= \033[31m
FINCOLOR	= \033[0m
SPY			= @

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

export option
export OPT

################################################################################

all: $(OTOOL) $(NM)

$(OTOOL): Makefile
	$(SPY)mv $(OTOOL) ./otool/ 2> /dev/null || true
	$(SPY)make $(OTOOL) -C otool/
	$(SPY)mv otool/$(OTOOL) ./ 2> /dev/null || true

$(NM): Makefile
	$(SPY)mv $(NM) ./nm/ 2> /dev/null || true
	$(SPY)make $(NM) -C nm/
	$(SPY)mv nm/$(NM) ./ 2> /dev/null || true

mv:
	$(SPY)mv $(OTOOL) otool/ 2> /dev/null || true
	$(SPY)mv $(NM) nm/ 2> /dev/null || true

clean: 
	$(SPY)make clean -C otool/
	$(SPY)make clean -C nm/

fclean: mv
	$(SPY)make fclean -C otool/
	$(SPY)make fclean -C nm/

re: fclean all

norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : $(OTOOL) - $(NM)\n$(FINCOLOR)"
	$(SPY)norminette include/*.h src/*.c
	$(SPY)make norme -C nm/
	$(SPY)make norme -C otool/


.PHONY : all clean fclean re norme $(NM) $(OTOOL)

################################################################################
