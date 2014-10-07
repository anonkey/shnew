/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 02:07:36 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 10:55:34 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_lang.h"

#define TOFLAG(a) (1 << (a))

typedef enum	e_toktype
{
	unknown,
	cmd,
	cmdarg,
	userinput,
	filename,
	lredir,
	llredir,
	lllredir,
	rredir,
	rrredir,
	pipe,
	and,
	or,
	semicol,
	nl,
	empty
}				t_toktype;

typedef enum	e_lexstate
{
	start,
	cmd,
	cmdarg,
	userinput,
	filename,
	lredir,
	llredir,
	lllredir,
	rredir,
	rrredir,
	pipe,
	and,
	or,
	semicol,
	nl,
	empty
}				t_toktype;

t_def				g_dictsh[DICT_LEN] =
{
	{NULL, 0, 0, cmd, (OPTYPE_SEP | EXTYPE_EMPTY), (OPTYPE_OP | EXTYPE_CMDARG)},
	{NULL, 0, 0, cmdarg, (OPTYPE_SEP | EXTYPE_EMPTY), (OPTYPE_OP | EXTYPE_CMDARG)},
	{NULL, 0, 0, userinput, TOFLAG(lllredir), (OPTYPE_OP | EXTYPE_CMDARG)},
	{NULL, 0, 0, filename, TOFLAG(lredir) | TOFLAG(rredir) | TOFLAG(rrredir), (OPTYPE_OP | EXTYPE_CMDARG)},
	{"<", 1, 2, lredir, EXTYPE_FILE},
	{"<<", 2, 2, llredir, EXTYPE_FILE},
	{"<<<", 3, 2, lllredir, EXTYPE_STDIN},
	{">", 1, 2, rredir, EXTYPE_FILE},
	{">>", 2, 2, rrredir, EXTYPE_FILE},
	{"|", 1, 2, pipe, EXTYPE_CMD},
	{"||", 2, 2, or, EXTYPE_CMD},
	{"&&", 2, 2, and, EXTYPE_CMD},
	{";", 1, 2, semicol, ((EXTYPE_CMD) | (EXTYPE_EMPTY))},
	{"\n", 1, 2, nl, ((EXTYPE_CMD) | (EXTYPE_EMPTY))}
};

typedef struct		s_lexer
{
	char			*strin;
	t_toktype		nextexprtype;
	t_token			tokact;
	t_lexstate		state;
	t_ldcd			toklist;
}					t_lexer;

typedef t_lexer		*t_lexer_p;

void				ft_lexdel(t_lexer_p *lex_p)
{
	if (!lex_p || !*lex_p)
		return ;
	ft_ldcddel(&((*lex_p)->toklist), NULL);
	ft_memdel((void **)lex_p);
}

t_lexer				ft_lexnew(char *strin)
{
	t_lexer_p	lex;

	if (!strin || !(lex = (t_lexer_p)ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	if (!(lex->toklist = ft_ldcdnew()))
	{
		ft_lexdel(&lex);
		return (NULL);
	}
	lex->state = start;
	lasttoktype = empty;
}

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
