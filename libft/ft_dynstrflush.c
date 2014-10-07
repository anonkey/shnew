/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstrflush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 14:25:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:32:22 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynstr.h"

char		*ft_dynstrflush(t_dynstr dstr)
{
	char			*res;
	t_ldcd_cell		iter;
	unsigned long	size;

	size = 0;
	if (!(res = ft_strnew(dstr->size)))
		return (NULL);
	iter = dstr->bufflist->head;
	while (iter && iter->next)
	{
		ft_strncpy(res + size, (char *)iter->content, iter->content_size);
		size += iter->content_size;
		iter = iter->next;
	}
	ft_strncpy(res + size, (char *)iter->content, dstr->offset);
	res[size + dstr->offset] = '\0';
	ft_ldcddel(&(dstr->bufflist), &ft_memdel);
	return (res);
}
