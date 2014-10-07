/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 14:22:36 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:31:55 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynstr.h"

void	ft_dynstrdel(t_dynstr *dstr_p)
{
	char	*str;

	while (ft_ldcdsize((*dstr_p)->bufflist) > 0)
	{
		str = ft_ldcdpop_back((*dstr_p)->bufflist);
		ft_strdel(&str);
	}
	ft_memdel((void **)dstr_p);
}
