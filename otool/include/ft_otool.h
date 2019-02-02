/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 18:46:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "ft_nm_otool.h"

/*
**	OPTION NM
*/
# define OPT_H				(1 << 0)	//Display header (.a -> tous les headers)
# define OPT_T				(1 << 1)		//	+ (verif pour les fats contenant ou non l'archi courante)
# define OPT_D				(1 << 2)
# define OPT_OTOOL			"htd"

typedef struct				s_env
{
	int						opt;			//bits
	unsigned long long		fstat_size;
	void					*ptr;
	uint32_t				magic_number;
}							t_env;

/*
** Env
*/

t_env						*env(void);
t_env						*ft_init_env(void);


/*
** Print
*/
void						ft_print_option_otool(void);

/*
** Error
*/
int							ft_usage_otool(void);

#endif
