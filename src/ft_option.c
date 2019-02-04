/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:35:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 18:46:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		ft_multi_args(int ind, int argc)
{
	if ((argc - ind) > 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int		ft_parse_option(int argc, char **argv, char *list_opt, int *env_opt)
{
	int opt;
	int	nb;
	int	i;

	nb = 1;
	if (argc == 1)
		return (nb);
	while (nb < argc && argv[nb])
	{
		i = 0;
		if (argv[nb][i] != '-' || !ft_strcmp(argv[nb], "--"))
			return ((argv[nb][i] != '-') ? nb : nb + 1);
		else if (ft_strlen(argv[nb]) < 2)
			return (EXIT_FAILURE);
		while (argv[nb][i + 1])
		{
			if ((opt = ft_chrstr_ind(argv[nb][i + 1], list_opt)) < 0)
				return (EXIT_FAILURE);
			*(env_opt) |= (1 << opt);
			i++;
		}
		nb++;
	}
	return (nb);
}
