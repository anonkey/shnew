/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:26:17 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 20:26:43 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_putnbr_ull(unsigned long long nbr)
{
	unsigned long	size;
	char			strout[MAX_ULLSIZE + 1];
	char			*act;

	size = 1;
	act = strout + MAX_ULLSIZE;
	*act-- = '\0';
	while (nbr >= 10)
	{
		*act = '0' + (char)(nbr % 10);
		--act;
		++size;
		nbr /= 10;
	}
	*act = '0' + nbr;
	ft_putstr(act);
	return (size);
}
