/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 11:00:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 11:44:30 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void				ft_lexdel(t_lexer_p *lex_p)
{
	if (!lex_p || !*lex_p)
		return ;
	ft_ldcddel(&((*lex_p)->toklist), NULL);
	ft_dynstrdel(&((*lex_p)->outstack), NULL);
	ft_memdel((void **)lex_p);
}

t_lexer				ft_lexnew(char *strin)
{
	t_lexer_p	lex;

	if (!strin || !(lex = (t_lexer_p)ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	if (!(lex->toklist = ft_ldcdnew()) || !(lex->outstack = ft_dynstrnew(1024)))
	{
		ft_lexdel(&lex);
		return (NULL);
	}
	lex->state = start;
	lasttoktype = empty;
}

int					ft_getinput_ind(char c)
{
	int		ind;

	if (-1 == (ind = ft_strchind(INPUT_CHARS)))
		ind = NB_INPUT_CHARS;
	return (ind);
}


