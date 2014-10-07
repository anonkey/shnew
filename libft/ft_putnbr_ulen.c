/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ulen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:26:54 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 20:44:44 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_ulen(unsigned long long nbr, int width, char fill)
{
	int			size;
	char		strout[MAX_LLSIZE + 1];
	char		*act;

	size = 1;
	act = strout + MAX_LLSIZE;
	*act-- = '\0';
	while (nbr >= 10)
	{
		*act = '0' + (char)(nbr % 10);
		--act;
		++size;
		nbr /= 10;
	}
	*act = '0' + nbr;
	while (++size <= width)
		*--act = fill;
	ft_putstr(act);
	return (size - 1);
}
