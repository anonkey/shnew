/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/03 14:28:39 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 14:34:52 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYNSTR_H
# define FT_DYNSTR_H
#include "libft.h"

typedef struct			s_dynstr
{
	t_ldcd				bufflist;
	unsigned long long	size;
	unsigned long		inc;
	unsigned long		offset;
}						t_sdynstr;

typedef t_sdynstr		*t_dynstr;

int						ft_dynstradd(t_dynstr dstr, char *str);

void					ft_dynstrdel(t_dynstr *dstr_p);

char					*ft_dynstrflush(t_dynstr dstr);

t_dynstr				ft_dynstrnew(unsigned long inc);

int						ft_dynstrput(t_dynstr dstr);

#endif