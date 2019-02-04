/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 18:39:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "ft_nm_otool.h"

/*
**	OPTION NM
*/
# define NM					"ft_nm: "

# define OPT_G				(1 << 0)	//Display symbols extern (only majuscule)
# define OPT_J				(1 << 1)	//Display only name of symbol (name function)
# define OPT_U				(1 << 2)	//Display only symbols undefined (U, u)
# define OPT_UU				(1 << 3)	//Display all except symbols undefined
# define OPT_R				(1 << 4)	//Order inverse
# define OPT_NM				"gjuUr"

typedef struct				s_env
{
	char					*cmd;
	int						opt;			//bits
	uint8_t					print_name;
	char					*file_name;
	size_t					file_size;
	void					*ptr;
	uint32_t				magic;
}							t_env;

/*
** Env
*/
t_env						*env(void);
t_env						*ft_init_env(void);
void						ft_reinit_env(void);


/*
** Print
*/
void						ft_print_option_nm(void);
void						ft_print_env(void);
void						ft_print_file(void);

/*
** Usage
*/
int							ft_usage_nm(void);

#endif
