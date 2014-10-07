/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldcd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 13:24:38 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 13:31:05 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ldcd_cell.h"

int		ft_putldcd(t_ldcd ldcd, void (*put)(void *))
{
	t_ldcd_cell		temp;
	t_ldcd_cell		iter;

	if (!ldcd)
		return (-1);
	iter = ldcd->head;
	while (iter)
	{
		*put(iter->content);
		iter = iter->next;
	}
	return (0);
}
