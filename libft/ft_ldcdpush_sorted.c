/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdpush_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:13:59 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/01 05:32:10 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ldcd_cell.h"

int		ft_ldcdpush_sorted(t_ldcd ldcd, void *elem, size_t elem_size,
							int (*cmp)(void *, void *))
{
	t_ldcd_cell		temp;
	t_ldcd_cell		iter;

	if (!ldcd)
		return (-1);
	iter = ldcd->head;
	while (iter && (*cmp)(iter->content, elem) < 0)
		iter = iter->next;
	if (!iter)
		return (ft_ldcdpush_back(ldcd, elem, elem_size));
	temp = ft_ldcd_cellnew(elem, elem_size);
	if (!temp)
		return (-1);
	temp->next = iter;
	temp->prev = iter->prev;
	if (iter->prev == NULL)
		ldcd->head = temp;
	else
		iter->prev->next = temp;
	temp->next->prev = temp;
	++(ldcd->size);
	return (0);
}
