/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:19:39 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 19:24:50 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readformat.h"

int		ft_floattype(t_printf_arg *arg)
{
	arg->type = arg->act;
	arg->state = STATE_END;
	return (0);
}

int		ft_printf_float(t_printf_arg *arg, char *format, va_list *args_p)
{
	long double		res;
	int				size;
	int				prec;

	(void)format;
	size = 0;
	prec = arg->prec == -1 ? DFL_FLOAT_PREC : arg->prec;
	if (arg->len == 0)
		res = (long double)va_arg(*args_p, double);
	else if (arg->len == PRINTF_DLLEN)
		res = (long double)va_arg(*args_p, long double);
	if (arg->type == 'f')
		size = ft_putldouble(res, prec,
							arg->flags & (1 << ft_strchind(PRINTF_FLAGS, '+')));
	else if (arg->type == 'e')
		size = ft_putldouble_sci(res, prec);
	return (size);
}
