/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 22:03:18 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 20:28:59 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getnbr_ll(long long nbr, int sign, char *strout)
{
	unsigned long	size;
	char			*act;

	size = 1;
	act = strout + MAX_LLSIZE;
	*act-- = '\0';
	if (nbr < 0 || sign)
	{
		++size;
		ft_putchar(nbr < 0 ? '-' : '+');
		nbr = nbr > 0 ? nbr : 0 - nbr;
	}
	while (nbr >= 10)
	{
		*act = '0' + (char)(nbr % 10);
		--act;
		nbr /= 10;
	}
	*act = '0' + nbr;
	return (strout);
}

int		ft_putnbr_ll(long long nbr, int sign)
{
	char		strout[MAX_LLSIZE + 1];

	return (ft_putstr(ft_getnbr_ll(nbr, sign, strout)));
}
