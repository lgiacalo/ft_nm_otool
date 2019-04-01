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

# define OTOOL					"ft_otool: "

# define OPT_T				(1 << 0)
# define OPT_D				(1 << 1)


int							ft_usage_otool(void);


#endif
