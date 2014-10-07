/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfloat_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:15:17 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 19:15:26 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readformat.h"

int		ft_dllen(t_printf_arg *arg)
{
	arg->len = PRINTF_DLLEN;
	arg->state = STATE_DLLEN;
	return (0);
}
