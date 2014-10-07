/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 14:22:50 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:01:06 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H
#define TOFLAG(a) (1 << (a))

typedef enum	e_toktype
{
	tok_unknown,
	tok_cmd,
	tok_cmdarg,
	tok_userinput,
	tok_filename,
	tok_lredir,
	tok_llredir,
	tok_lllredir,
	tok_rredir,
	tok_rrredir,
	tok_pipe,
	tok_and,
	tok_or,
	tok_bg,
	tok_semicol,
	tok_nl,
	tok_empty
}				t_toktype;

#endif /* !FT_TOKEN_H */
