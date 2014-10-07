/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 02:07:36 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:42:16 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_lang.h"
#include "ft_token.h"


t_def				g_dictsh[DICT_LEN] =
{
	{NULL, 0, 0, tok_cmd, (TOK_OP | tok_cmd)},
	{NULL, 0, 0, tok_cmdarg, (TOK_OP | TOFLAG(tok_cmdarg))},
	{NULL, 0, 0, tok_userinput, (TOK_OP | TOFLAG(tok_cmdarg))},
	{NULL, 0, 0, tok_filename, (TOK_OP | TOFLAG(tok_cmdarg))},
	{"<", 1, 2, tok_lredir, TOFLAG(tok_filename)},
	{"<<", 2, 2, tok_llredir, TOFLAG(tok_filename)},
	{"<<<", 3, 2, tok_lllredir, TOFLAG(tok_userinput)},
	{">", 1, 2, tok_rredir, TOFLAG(tok_filename)},
	{">>", 2, 2, tok_rrredir, TOFLAG(tok_filename)},
	{"|", 1, 2, tok_pipe, TOFLAG(tok_cmd)},
	{"&", 1, 2, tok_bg, TOK_TERMSEP | TOFLAG(tok_cmd)},
	{"||", 2, 2, tok_or, TOFLAG(tok_cmd)},
	{"&&", 2, 2, tok_and, TOFLAG(tok_cmd)},
	{";", 1, 2, tok_semicol, (TOFLAG(tok_cmd) | (TOFLAG(tok_empty)))},
	{"\n", 1, 2, tok_nl, (TOFLAG(tok_cmd) | (TOFLAG(tok_empty)))}
};

int					ft_isop(t_dict dict, char *str, int len)
{
	return ((-1 == ft_getopind(dict, str, len)) ? 0 : 1);
}

int					ft_getopind(t_dict dict, char *str, int len)
{
	int		i;
	int		res;
	int		len;

	res = -1;
	i = 0;
	while (i < DICT_LEN)
	{
		if (len >= dict[i].len
			&& dict[i].len > len
			&& !ft_strncmp(dict[i].mark, str, dict[i].len))
		{
			len = dict[i].len;
			res = i;
		}
		++i;
	}
	return (res);
}


int					main(int argc, char **argv)
{
	t_ldcd		toklist;
	char		buffer[1024];

	buffer[0] = '\0';

	return (0);
}
