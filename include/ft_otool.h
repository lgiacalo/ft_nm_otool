/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:19:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "ft_nm_otool.h"

/*
**	OPTION OTOOL
*/

# define NM					"ft_nm: "

# define OPT_G				(1 << 0)
# define OPT_J				(1 << 1)
# define OPT_U				(1 << 2)
# define OPT_UU				(1 << 3)
# define OPT_R				(1 << 4)
# define OPT_A				(1 << 5)
# define OPT_NM				"gjuUra"


int							ft_usage_otool(void);

#endif
