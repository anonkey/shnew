/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:12:18 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 21:18:34 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readformat.h"

int		ft_pointtype(t_printf_arg *arg)
{
	arg->type = arg->act;
	arg->state = STATE_END;
	return (0);
}

int		ft_printf_point(t_printf_arg *arg, char *format, va_list *args_p)
{
	void	*res;
	int		size;

	(void)format;
	(void)arg;
	res = va_arg(*args_p, void *);
	if (res)
	{
		size = ft_putstr("0x");
		size += ft_putnbrhex((unsigned long)res, arg->width, 0);
	}
	else
		size = ft_putstr(NULLPTR_STR);
	return (size);
}
