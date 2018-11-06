/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:43:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/11/07 00:36:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

void	print_output(char *ptr, int nsyms, int symoff, int stroff)
{
	int				i;
	char			*strtable;
	struct nlist_64	*array;

	array = (void *)ptr + symoff;
	strtable = (void *)ptr + stroff;
	while (i < nsyms)
	{
		printf("%s\n", strtable + array[i].n_un.n_strx);
		i++;
	}
}

void	handle_64(char *ptr)
{
	int						i;
	int						ncmds;
	struct mach_header_64	*header64;
	struct load_command		*lc;
	struct symtab_command	*sym;
	struct dysymtab_command	*dysym;

	header64 = (struct mach_header_64 *)ptr;
	ncmds = header64->ncmds;
	printf("Nbr ncmds = %d\n", header64->ncmds);
	i = 0;
	lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			printf("Trouveeee LC_SYMTAB : nb symboles = %d\n", sym->nsyms);
			print_output(ptr, sym->nsyms, sym->symoff, sym->stroff);
			break;
		}
		if (lc->cmd == LC_DYSYMTAB)
		{
			dysym = (struct dysymtab_command *)lc;
			print_output(ptr, dysym->nsyms, dysym->symoff, dysym->stroff);
			break;
		}
		lc  = (void *)lc + lc->cmdsize;
		i++;
	}
}

void	ft_nm(char *ptr)
{
	int	magic_number;
	
	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(ptr);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*ptr;
	struct stat	buf;

	if (argc != 2)
	{
		fprintf(stderr, "Please give me an arg\n");
		return (EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("open");
		return (EXIT_FAILURE);
	}
	if (fstat(fd, &buf) < 0)
	{
		perror("fstat");
		return (EXIT_FAILURE);
	}
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		perror("mmap");
		return (EXIT_FAILURE);
	}
	ft_nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
	{
		perror("munmap");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
