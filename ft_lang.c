/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 02:07:36 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 14:23:28 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_lang.h"
#include "ft_token.h"


t_def				g_dictsh[DICT_LEN] =
{
	{NULL, 0, 0, tok_cmd, (OPTYPE_OP | EXTYPE_CMDARG)},
	{NULL, 0, 0, tok_cmdarg, (OPTYPE_OP | EXTYPE_CMDARG)},
	{NULL, 0, 0, tok_userinput, (OPTYPE_OP | EXTYPE_CMDARG)},
	{NULL, 0, 0, tok_filename, (OPTYPE_OP | EXTYPE_CMDARG)},
	{"<", 1, 2, tok_lredir, EXTYPE_FILE},
	{"<<", 2, 2, tok_llredir, EXTYPE_FILE},
	{"<<<", 3, 2, tok_lllredir, EXTYPE_STDIN},
	{">", 1, 2, tok_rredir, EXTYPE_FILE},
	{">>", 2, 2, tok_rrredir, EXTYPE_FILE},
	{"|", 1, 2, tok_pipe, EXTYPE_CMD},
	{"&", 1, 2, tok_bg, OPTYE_TERMSEP | EXTYPE_CMD},
	{"||", 2, 2, tok_or, EXTYPE_CMD},
	{"&&", 2, 2, tok_and, EXTYPE_CMD},
	{";", 1, 2, tok_semicol, ((EXTYPE_CMD) | (EXTYPE_EMPTY))},
	{"\n", 1, 2, tok_nl, ((EXTYPE_CMD) | (EXTYPE_EMPTY))}
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
