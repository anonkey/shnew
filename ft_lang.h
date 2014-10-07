/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:21:00 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:35:45 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LANG_H
# define FT_LANG_H

/*
** Language limits constants
*/
/*
** Language special chars
*/
# define INHIB_CHAR '\\'
# define INHIB_ZONE '\''
# define HALFINHIB_ZONE '\"'
# define IFS " \t\v"

/*
** Operators definiton's type
*/
# define TOK_EXPR (TOFLAG(tok_cmd) | TOFLAG(tok_cmdarg) | TOFLAG(tok_userinput) | TOFLAG(tok_filename))
# define TOK_LREDIR (TOFLAG(tok_lredir) | TOFLAG(tok_llredir) | TOFLAG(tok_lllredir))
# define TOK_RREDIR (TOFLAG(tok_rredir) | TOFLAG(tok_rrredir))
# define TOK_REDIR (TOK_LREDIR | TOK_RREDIR)
# define TOK_LISTSEP (TOFLAG(tok_and) | TOFLAG(tok_or))
# define TOK_TERMSEP (TOFLAG(tok_semicol) | TOFLAG(tok_nl) | TOFLAG(tok_bg))
# define TOK_OP (TOK_REDIR | TOK_LISTSEP | TOK_TERMSEP | TOFLAG(tok_pipe))
typedef struct		s_def
{
	char			mark[OP_MAX_LEN];
	int				len;
	int				opnb;
	int				type;
	int				ltype;
	int				rtype;
}					t_def;

typedef t_def		t_dict[DICT_LEN];

extern t_dict		g_dictsh;

int					ft_isop(t_dict dict, char *str, int len);

int					ft_getopind(t_dict dict, char *str, int len);

#endif
