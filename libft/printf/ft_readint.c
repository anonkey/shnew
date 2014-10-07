/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:16:06 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/01 00:48:48 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readformat.h"

int		ft_inttype(t_printf_arg *arg)
{
	arg->type = arg->act;
	arg->state = STATE_END;
	return (0);
}

int		ft_printf_integer(t_printf_arg *arg, char *format, va_list *args_p)
{
	long long	res;
	int			size;

	(void)format;
	size = 0;
	if (arg->len == 0 || arg->len == PRINTF_HLEN || arg->len == PRINTF_HHLEN)
		res = (long long)va_arg(*args_p, int);
	else if (arg->len == PRINTF_LLEN)
		res = (long long)va_arg(*args_p, long);
	else if (arg->len == PRINTF_LLLEN)
		res = va_arg(*args_p, long long);
	else if (arg->len == PRINTF_ZLEN)
	{
		arg->width = arg->prec;
		res = (long long)va_arg(*args_p, size_t);
	}
	if (arg->width < 0)
		arg->width = 0;
	if (arg->type == 'd' || arg->type == 'i')
		size = ft_putnbr_len(res,
							(arg->flags
							& (1 << ft_strchind(PRINTF_FLAGS, '+')) ? 1 : 0),
							arg->width, '0');
	else if (arg->type == 'x' || arg->type == 'X')
		size = ft_putnbrhex(res, arg->width, arg->type == 'X' ? 1 : 0);
	else if (arg->type == 'o')
		size = ft_putnbr_oct((unsigned long long)res, arg->width);
	else if (arg->type == 'u')
		size = ft_putnbr_ulen(res, arg->width, '0');
	return (size);
}
