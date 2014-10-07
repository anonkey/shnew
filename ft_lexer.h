/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 11:00:08 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 14:39:16 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H
# include "libft.h"
# include "ft_token.h"
# define NB_INPUT_CHARS 6
# define INPUT_CHARS "<>|&;\n"


typedef enum		e_lexstate
{
					state_start,
					state_expr,
					state_lredir,
					state_llredir,
					state_lllredir,
					state_rredir,
					state_rrredir,
					state_pipe,
					state_bg,
					state_and,
					state_or,
					state_semicol,
					state_nl,
					state_end
}					t_lexstate;

typedef struct		s_lexer
{
	char			*strin;
	t_dynstr		outstack;
	t_toktype		nextexprtype;
	t_toktype		actexprtype;
	t_lexstate		state;
	t_ldcd			toklist;
}					t_lexer;

typedef t_lexer		*t_lexer_p;

typedef int (*t_lexfunc)(t_lexer_p);

void				ft_lexdel(t_lexer_p *lex_p);

t_lexer				*ft_lexnew(char *strin);

int					ft_getinput_ind(char c);

#endif /* !FT_LEXER_H */
