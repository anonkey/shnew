/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstradd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 14:23:38 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:31:31 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynstr.h"

static int		ft_dynstr_extend(t_dynstr dstr, unsigned long size)
{
	void	*buffer;

	if (!(buffer = ft_strnew(size + dstr->inc)))
		return (-1);
	if (-1 == ft_ldcdpush_back(dstr->bufflist, buffer, size + dstr->inc))
	{
		free(buffer);
		return (-1);
	}
		free(buffer);
	dstr->offset = 0;
	return (0);
}

int				ft_dynstradd(t_dynstr dstr, char *str)
{
	unsigned long	size;
	unsigned long	freebytes;

	size = ft_strlen(str);
	if (!(ft_ldcdsize(dstr->bufflist)) || dstr->bufflist->tail->content_size - dstr->offset - 1 < size)
	{
		if (dstr->bufflist->tail)
		{
			freebytes = dstr->bufflist->tail->content_size - dstr->offset;
			ft_strncpy((char *)(dstr->bufflist->tail->content + dstr->offset), str, freebytes);
			size -= freebytes;
			str += freebytes;
			dstr->size += freebytes;
		}
		if (-1 == ft_dynstr_extend(dstr, size))
			return (-1);
	}
	ft_strcpy((char *)(dstr->bufflist->tail->content + dstr->offset), str);
	dstr->offset += size;
	dstr->size += size;
	return (0);
}


