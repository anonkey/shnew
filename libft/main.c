/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:10:45 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/01 00:31:10 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	long	a;
	size_t	toto;

	toto = 203032;
	a = 1000000;
	printf(" \n A%dA", ft_printf("\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %+10.10zd  %6.6zx %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x100UL, 12.42, 1.11111111, 3.14127));
	printf(" \n A%dA", printf("\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %+10.10zd  %6.6zx %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x100UL, 12.42, 1.111111111, 3.14127));
	ft_printf("\n %p \n", NULL);
	printf("\n %p \n", NULL);
	return (0);
}
