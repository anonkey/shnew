/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 11:00:08 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 12:22:02 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H
# include "libft.h"
# define NB_INPUT_CHARS 6
# define INPUT_CHARS "<>|&;\n"


typedef enum		e_lexstate
{
					start,
					expr,
					lredir,
					llredir,
					lllredir,
					rredir,
					rrredir,
					pipe,
					bg,
					and,
					or,
					semicol,
					nl,
					end
}					t_lexstate;

typedef struct		s_lexer
{
	char			*strin;
	t_dynstr		outstack;
	t_toktype		nextexprtype;
	t_toktype		lasttype;
	t_lexstate		state;
	t_ldcd			toklist;
}					t_lexer;

typedef int (*t_lexfunc)(t_lexer);

typedef t_lexer		*t_lexer_p;

t_lexfunc			g_lexmatrix[][] =
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
/* bg */		{NULL, NULL, NULL, &ft_and, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* and */		{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* or */		{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* semicol */	{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
/* nl */		{NULL, NULL, NULL, NULL, NULL, NULL, &ft_flush, &ft_expr, NULL},
}

void				ft_lexdel(t_lexer_p *lex_p);

t_lexer				ft_lexnew(char *strin);

int					ft_getinput_ind(char c);

#endif /* !FT_LEXER_H */
