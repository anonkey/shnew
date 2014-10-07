/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:31:45 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/01 00:18:14 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readarg.h"

int		ft_printarg(t_printf_arg arg, char *format, va_list *args_p)
{
	t_printfn	*printfunc;

	if (!(printfunc = ft_getprint_fn(arg.type)))
		return (0);
	return (printfunc->print(&arg, format, args_p));
}

int		ft_writearg(int *index_p, char *format, va_list *args_p)
{
	t_printf_arg	arg;

	if (-1 == (arg.flags = ft_readflags(index_p, format)))
		return (-1);
	if (-1 == (arg.width = ft_readwidth(index_p, format)))
		return (-2);
	if (-2 == (arg.prec = ft_readprec(index_p, format)))
		return (-3);
	if (-1 == ft_readtype(&arg, index_p, format))
		return (-4);
	return (ft_printarg(arg, format, args_p));
}

int		ft_printf(char *format, ...)
{
	va_list		args;
	int			index;
	ULONG		size;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
			size += ft_writearg(&index, format, &args);
		}
		else
		{
			ft_putchar(format[index]);
			++size;
			++index;
		}
	}
	va_end(args);
	return (size);
}
