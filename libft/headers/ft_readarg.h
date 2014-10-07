/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readarg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:01:54 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 19:02:31 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READARG_H
# define FT_READARG_H
# include <stdarg.h>
# include "libft.h"
# include "ft_readformat.h"

# define ULONG unsigned long
# define NB_PRINT_FN 5

t_printfn	*ft_getprint_fn(char c);

char		ft_readflags(int *index_p, char *format);

int			ft_readwidth(int *index_p, char *format);

int			ft_readprec(int *index_p, char *format);

int			ft_getpars_fnind(char c);

int			ft_readtype(t_printf_arg *arg_p, int *index_p, char *format);

#endif
