/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 14:21:54 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:32:36 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynstr.h"

t_dynstr	ft_dynstrnew(unsigned long inc)
{
	t_dynstr	str;

	if (!(str = (t_dynstr)ft_memalloc(sizeof(t_sdynstr))))
		return (NULL);
	if (!(str->bufflist = ft_ldcdnew()))
	{
		ft_memdel((void **)&str);
		return (NULL);
	}
	str->inc = inc;
	return (str);
}
