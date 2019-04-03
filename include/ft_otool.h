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
# define OPT_M				(1 << 2)

int							ft_usage_otool(void);

struct section_64					*ft_swap_section_64(uint32_t magic, struct section_64 *sect);
struct section						*ft_swap_section(uint32_t magic, struct section *sect);

int		ft_record_section_64(uint32_t magic, void *ptr, struct section_64 *dst);

struct section_64					ft_copy_section_64(struct section *src);

void	                   ft_print_section(struct section_64 *sect);
void	                   ft_print_title_otool(void);

#endif
