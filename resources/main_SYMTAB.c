/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:43:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/24 15:30:07 by lgiacalo         ###   ########.fr       */
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

	i = 0;
	array = (void *)ptr + symoff;
	strtable = (void *)ptr + stroff;
	printf("Sizeof nlist_64 = %lu\n", sizeof(struct nlist_64));
	printf("LC_SYMYAB : stroff = %d / symoff = %d\n\n", stroff, symoff);
	while (i < nsyms)
	{
		if (!(array[i].n_type & N_STAB))
		{
			printf("%016llx %s\n", array[i].n_value, strtable + array[i].n_un.n_strx);
			printf("\t +%d <= n_strx / i = %d\t / n_type = %#x / n_sect = %d\n\n\n", array[i].n_un.n_strx, i, array[i].n_type, array[i].n_sect);
		}
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
			printf("Trouveeee LC_SYMTAB : nsyms = %d / strsize = %d\n", sym->nsyms, sym->strsize);
			print_output(ptr, sym->nsyms, sym->symoff, sym->stroff);
			break;
		}
		lc  = (void *)lc + lc->cmdsize;
		i++;
	}
}

void	ft_nm(char *ptr)
{
	int	magic;
	
	magic = *(int *)ptr;
	if (magic == MH_MAGIC_64)
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
