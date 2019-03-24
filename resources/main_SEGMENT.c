/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:43:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/24 15:01:17 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
void	print_output(char *ptr, int nsyms, int symoff, int stroff)
{
	int				i;
	char			*strtable;
	struct nlist_64	*array;

	array = (void *)ptr + symoff;
	strtable = (void *)ptr + stroff;
	printf("Sizeof nlist_64 = %lu\n", sizeof(struct nlist_64));
	printf("LC_SYMYAB : stroff = %d / symoff = %d\n\n", stroff, symoff);
	while (i < nsyms)
	{
		printf("%s\t", strtable + array[i].n_un.n_strx);
		printf("\t +%d <= n_strx\n", array[i].n_un.n_strx);
		i++;
	}
	printf("LASt %s\t", strtable + array[i].n_un.n_strx);
	printf("\t +%d <= n_strx\n", array[i].n_un.n_strx);
}
*/

void	print_output(char *ptr, struct section_64 *sect)
{

	printf("%d\n", sect->reserved1);
	printf("%d\n", sect->reserved2);
	printf("%d\n", sect->reserved3);
}

void	handle_section(char *ptr, struct segment_command_64 *seg)
{
	int					i;
	struct section_64	*sect;

	printf("Nbr sections : %d\n", seg->nsects);
	i = 0;
	sect = (void *)seg + sizeof(struct segment_command_64);
	while (i < seg->nsects)
	{
		printf("\tSectname = %s\n", sect->sectname);
		print_output(ptr, sect);
		i++;
		sect = (void *)sect + sizeof(struct section_64);
	}
}

void	handle_64(char *ptr)
{
	int							i;
	int							ncmds;
	struct mach_header_64		*header64;
	struct load_command			*lc;
	struct segment_command_64	*seg;

	header64 = (struct mach_header_64 *)ptr;
	ncmds = header64->ncmds;
	printf("Nbr ncmds = %d\n", header64->ncmds);
	i = 0;
	lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			printf("Trouveeee LC_SEGMENT : name : %s\n", seg->segname);
			handle_section(ptr, seg);
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
