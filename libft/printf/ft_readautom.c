/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readautom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:27:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 19:29:08 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readarg.h"

char		*g_printfinput_tab[10] =
{
	"h",
	"l",
	"z",
	"diouxX",
	"s",
	"c",
	"p",
	"L",
	"fe",
	NULL
};

t_parsefunc		g_parsefn_tab[7][9] =
{
	{&ft_hlen, &ft_llen, &ft_zlen, &ft_inttype, &ft_strtype, &ft_chartype,
		&ft_pointtype, &ft_dllen, &ft_floattype},
	{&ft_hhlen, NULL, NULL, &ft_inttype, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, &ft_inttype, NULL, NULL, NULL, NULL, NULL},
	{NULL, &ft_lllen, NULL, &ft_inttype, &ft_strtype, &ft_chartype, NULL, NULL,
		NULL},
	{NULL, NULL, NULL, &ft_inttype, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &ft_floattype},
	{NULL, NULL, NULL, &ft_inttype, NULL, NULL, NULL, NULL, NULL}
};

int				ft_getpars_fnind(char c)
{
	int		i;

	i = 0;
	while (g_printfinput_tab[i])
	{
		if (ft_strchr(g_printfinput_tab[i], c))
			return (i);
		++i;
	}
	return (-1);
}

int				ft_readtype(t_printf_arg *arg_p, int *index_p, char *format)
{
	int		charind;

	arg_p->type = 0;
	arg_p->len = 0;
	arg_p->state = STATE_START;
	while (arg_p->state != STATE_END
		&& -1 != (charind = ft_getpars_fnind(format[*index_p]))
		&& (g_parsefn_tab[arg_p->state][charind]))
	{
		arg_p->act = format[*index_p];
		if (-1 == g_parsefn_tab[arg_p->state][charind](arg_p))
			return (0);
		++*index_p;
	}
	return (arg_p->state == STATE_END ? 0 : -1);
}
