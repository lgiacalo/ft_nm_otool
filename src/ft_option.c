/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:35:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 18:41:08 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		ft_parse_option(int argc, char **argv, char *list_opt, int *env_opt)
{
	int opt;
	int	nb;
	int	i;

	if (argc == 1)
		return (1);
	nb = 1;
	while (nb < argc && argv[nb])
	{
		i = 0;
		if (argv[nb][i] != '-' || !ft_strcmp(argv[nb], "--"))
			return (1);
		else if (ft_strlen(argv[nb]) < 2)
			return (0);
		while (argv[nb][i + 1])
		{
			if ((opt = ft_chrstr_ind(argv[nb][i + 1], list_opt)) < 0)
				return (0);
			*(env_opt) |= (1 << opt);
			i++;
		}
		nb++;
	}
	return (1);
}
