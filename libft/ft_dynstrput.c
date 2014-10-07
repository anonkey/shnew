/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstrput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 14:24:31 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:37:37 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_dynstr.h"

int		ft_dynstrput(t_dynstr dstr)
{
	t_ldcd_cell		iter;

	iter = dstr->bufflist->head;
	while (iter)
	{
		write(1, (char *)iter->content, iter->content_size);
		iter = iter->next;
	}
	return (dstr->size);
}
