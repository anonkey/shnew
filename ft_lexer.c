/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 11:00:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:01:04 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_token.h"

void				ft_lexdel(t_lexer_p *lex_p)
{
	if (!lex_p || !*lex_p)
		return ;
	ft_ldcddel(&((*lex_p)->toklist), NULL);
	ft_dynstrdel(&((*lex_p)->outstack));
	ft_memdel((void **)lex_p);
}

t_lexer_p				ft_lexnew(char *strin)
{
	t_lexer_p	lex;

	if (!strin || !(lex = (t_lexer_p)ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	if (!(lex->toklist = ft_ldcdnew()) || !(lex->outstack = ft_dynstrnew(1024)))
	{
		ft_lexdel(&lex);
		return (NULL);
	}
	lex->state = state_start;
	lex->actexprtype = tok_cmd;
	return (lex);
}

int					ft_getinput_ind(char c)
{
	int		ind;

	if (-1 == (ind = ft_strchind(INPUT_CHARS, c)))
		ind = NB_INPUT_CHARS;
	return (ind);
}

int			ft_flush(t_lexer_p lex)
{
	char	*token;

	if (lex->outstack->size <= 0)
		return (0);
	token = ft_dynstrflush(lex->outstack);
	*token = '0' + (char)lex->nextexprtype;
	return (ft_ldcdpush_back(lex->toklist, token, ft_strlen(token) + 1));
}

int			ft_stack(t_lexer_p lex)
{
	char	tmp;

	tmp = lex->strin[1];
	lex->strin[1] = '\0';
	ft_dynstradd(lex->outstack, lex->strin);
	lex->strin[1] = tmp;
	return (0);
}

int			ft_lredir(t_lexer_p lex)
{
	ft_flush(lex);
	ft_stack(lex);
	lex->nextexprtype = tok_filename;
	lex->state = state_lredir;
	return (0);
}

int			ft_llredir(t_lexer_p lex)
{
	ft_stack(lex);
	lex->nextexprtype = tok_filename;
	lex->state = state_llredir;
	return (0);
}

int			ft_lllredir(t_lexer_p lex)
{
	ft_stack(lex);
	lex->nextexprtype = tok_userinput;
	lex->state = state_lllredir;
	return (0);
}

int			ft_rredir(t_lexer_p lex)
{
	ft_flush(lex);
	ft_stack(lex);
	lex->nextexprtype = tok_filename;
	lex->state = state_rredir;
	return (0);
}

int			ft_rrredir(t_lexer_p lex)
{
	ft_stack(lex);
	lex->state = state_rrredir;
	return (0);
}

int			ft_pipe(t_lexer_p lex)
{
	ft_flush(lex);
	ft_stack(lex);
	lex->nextexprtype = tok_cmd;
	lex->state = state_pipe;
	return (0);
}

int			ft_bg(t_lexer_p lex)
{
	ft_flush(lex);
	ft_stack(lex);
	lex->nextexprtype = tok_cmd;
	lex->state = state_bg;
	return (0);
}

int			ft_or(t_lexer_p lex)
{
	ft_stack(lex);
	lex->nextexprtype = tok_cmd;
	lex->state = state_or;
	return (0);
}

int			ft_and(t_lexer_p lex)
{
	ft_stack(lex);
	lex->nextexprtype = tok_cmd;
	lex->state = state_and;
	return (0);
}

int			ft_semicol(t_lexer_p lex)
{
	ft_flush(lex);
	ft_stack(lex);
	lex->nextexprtype = tok_cmd;
	lex->state = state_semicol;
	return (0);
}

int			ft_nl(t_lexer_p lex)
{
	ft_flush(lex);
	ft_stack(lex);
	lex->nextexprtype = tok_cmd;
	lex->state = state_nl;
	return (0);
}

int			ft_expr(t_lexer_p lex)
{
	if (lex->state != state_expr)
		ft_flush(lex);
	lex->actexprtype = lex->nextexprtype;
	lex->nextexprtype = tok_cmdarg;
	lex->state = state_expr;
	return (0);
}

int			ft_end(t_lexer_p lex)
{
	ft_flush(lex);
	lex->nextexprtype = tok_unknown;
	lex->state = state_end;
	return (0);
}


t_lexfunc			g_lexmatrix[13][9] =
{
			/*   < ,         > ,          | ,       & ,       ; ,          \n , IFS , others , \0*/
/* start */		{&ft_lredir, &ft_rredir, &ft_pipe, &ft_bg, &ft_semicol, &ft_nl, &ft_flush, &ft_expr, &ft_end},
/* expr */		{&ft_lredir, &ft_rredir, &ft_pipe, &ft_bg, &ft_semicol, &ft_nl, &ft_flush, &ft_expr, &ft_end},
/* lredir */	{&ft_llredir, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* llredir */	{&ft_lllredir, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* lllredir */	{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* rredir */	{&ft_rrredir, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* rrredir */	{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* pipe */		{NULL, NULL, &ft_or, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* bg */		{NULL, NULL, NULL, &ft_and, &ft_semicol, &ft_nl, &ft_flush, &ft_expr, &ft_end},
/* and */		{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* or */		{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* semicol */	{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* nl */		{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
};

