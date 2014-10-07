/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:29:23 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 19:30:29 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_readarg.h"
#include "ft_readformat.h"

char	ft_readflags(int *index_p, char *format)
{
	int		pos;
	char	flag;

	flag = '\0';
	while (-1 != (pos = ft_strchind(PRINTF_FLAGS, format[*index_p])))
	{
		flag |= 1 << pos;
		++*index_p;
	}
	return (flag);
}

int		ft_readwidth(int *index_p, char *format)
{
	int		width;

	width = 0;
	if (format[*index_p] >= '1' && format[*index_p] <= '9')
	{
		while (format[*index_p] >= '0' && format[*index_p] <= '9')
		{
			width *= 10;
			width += (int)(format[*index_p] - '0');
			++*index_p;
		}
	}
	return (width);
}

int		ft_readprec(int *index_p, char *format)
{
	int		prec;

	prec = -1;
	if (format[*index_p] == '.')
	{
		prec = 0;
		++*index_p;
		while (format[*index_p] >= '0' && format[*index_p] <= '9')
		{
			prec *= 10;
			prec += (int)(format[*index_p] - '0');
			++*index_p;
		}
	}
	return (prec);
}
