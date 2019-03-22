/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_cpu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:10:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:48:31 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
**	A verifier avec NXGetAllArchInfos()
*/

static const t_1s2n g_infos[52] = {
	{"any", CPU_TYPE_ANY, CPU_SUBTYPE_MULTIPLE},
	{"little", CPU_TYPE_ANY, CPU_SUBTYPE_LITTLE_ENDIAN},
	{"big", CPU_TYPE_ANY, CPU_SUBTYPE_BIG_ENDIAN},
	{"arm", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_ALL},
	{"armv4t", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V4T},
	{"armv5", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V5TEJ},
	{"armv6", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V6},
	{"armv6m", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V6M},
	{"armv7", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7},
	{"armv7em", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7EM},
	{"armv7f", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7F},
	{"armv7k", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7K},
	{"armv7m", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7M},
	{"armv7s", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7S},
	{"armv8", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V8},
	{"xscale", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_XSCALE},
	{"arm64", CPU_TYPE_ARM64, CPU_SUBTYPE_ARM64_ALL},
	{"arm64", CPU_TYPE_ARM64, CPU_SUBTYPE_ARM64_V8},
	{"hppa", CPU_TYPE_HPPA, CPU_SUBTYPE_HPPA_ALL},
	{"hppa7100LC", CPU_TYPE_HPPA, CPU_SUBTYPE_HPPA_7100LC},
	{"i386", CPU_TYPE_I386, CPU_SUBTYPE_I386_ALL},
	{"i486", CPU_TYPE_I386, CPU_SUBTYPE_486},
	{"i486SX", CPU_TYPE_I386, CPU_SUBTYPE_486SX},
	{"i586", CPU_TYPE_I386, CPU_SUBTYPE_586},
	{"i686", CPU_TYPE_I386, CPU_SUBTYPE_PENTPRO},
	{"i860", CPU_TYPE_I860, CPU_SUBTYPE_I860_ALL},
	{"x86_64", CPU_TYPE_I386, CPU_SUBTYPE_X86_64_H},
	{"pentIIm3", CPU_TYPE_I386, CPU_SUBTYPE_PENTII_M3},
	{"pentIIm5", CPU_TYPE_I386, CPU_SUBTYPE_PENTII_M5},
	{"pentium", CPU_TYPE_I386, CPU_SUBTYPE_PENT},
	{"pentium4", CPU_TYPE_I386, CPU_SUBTYPE_PENTIUM_4},
	{"pentpro", CPU_TYPE_I386, CPU_SUBTYPE_PENTPRO},
	{"m68030", CPU_TYPE_MC680x0, CPU_SUBTYPE_MC68030_ONLY},
	{"m68040", CPU_TYPE_MC680x0, CPU_SUBTYPE_MC68040},
	{"m68k", CPU_TYPE_MC680x0, CPU_SUBTYPE_MC680x0_ALL},
	{"m88k", CPU_TYPE_MC88000, CPU_SUBTYPE_MC88000_ALL},
	{"ppc", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_ALL},
	{"ppc601", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_601},
	{"ppc603", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_603},
	{"ppc603e", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_603e},
	{"ppc603ev", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_603ev},
	{"ppc604", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_604},
	{"ppc604e", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_604e},
	{"ppc7450", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_7450},
	{"ppc750", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_750},
	{"ppc970", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_970},
	{"ppc64", CPU_TYPE_POWERPC64, CPU_SUBTYPE_POWERPC_ALL},
	{"ppc970-64", CPU_TYPE_POWERPC64, CPU_SUBTYPE_POWERPC_970},
	{"sparc", CPU_TYPE_SPARC, CPU_SUBTYPE_SPARC_ALL},
	{"x86_64", CPU_TYPE_X86_64, CPU_SUBTYPE_X86_64_ALL},
	{"x86_64", CPU_TYPE_X86_64, 0x80000003},
	{"x86_64", CPU_TYPE_X86_64, CPU_SUBTYPE_X86_64_H}
};

/*
**	Inutile pour linstant
*/

char	*ft_get_name_cpu(int cputype, int cpusubtype)
{
	unsigned int	i;
	unsigned int	j;


	if (cputype == CPU_TYPE_X86_64)
		ft_fdprintf(FDD, "CPU_TYPE_X86_64 : yes = %d!!\n", CPU_TYPE_X86_64);
	if ((cpusubtype & ~CPU_SUBTYPE_MASK) == CPU_SUBTYPE_X86_64_ALL)
		ft_fdprintf(FDD, "CPU_SUBTYPE_X86_64_ALL : yes = %d!!\n", CPU_SUBTYPE_X86_64_ALL);
	i = -1;
	while (++i < 52)
	{
		if (cputype == g_infos[i].n1)
		{
			j = i - 1;
			while (cputype == g_infos[++j].n1)
				if (cpusubtype == g_infos[j].n2)
					return (g_infos[j].s1);
			return ("");
		}
	}
	return ("");
}

struct fat_arch_64	ft_copy_fat_arch_64(struct fat_arch *src)
{
	struct fat_arch_64	dst;

	dst.cputype = src->cputype;
	dst.cpusubtype = src->cpusubtype;
	dst.offset = src->offset;
	dst.size = src->size;
	dst.align = src->align;
	dst.reserved = 0;
	return (dst);
}
