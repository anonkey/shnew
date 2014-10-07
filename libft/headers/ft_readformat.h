/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readformat.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:04:43 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 21:19:42 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READFORMAT_H
# define FT_READFORMAT_H

# include <stdarg.h>
# include "libft.h"
# define NULLPTR_STR "0x0"
# define DFL_FLOAT_PREC 6
# define PRINTF_FLAGS "#0- +"

# define PRINTF_HLEN 1
# define PRINTF_HHLEN 2
# define PRINTF_LLEN 3
# define PRINTF_LLLEN 4
# define PRINTF_DLLEN 5
# define PRINTF_ZLEN 6

# define STATE_START 0
# define STATE_HLEN 1
# define STATE_HHLEN 2
# define STATE_LLEN 3
# define STATE_LLLEN 4
# define STATE_DLLEN 5
# define STATE_ZLEN 6
# define STATE_END 7

typedef struct		s_printf_arg
{
	char			flags;
	int				width;
	int				prec;
	int				len;
	char			type;
	int				state;
	char			act;
}					t_printf_arg;

typedef int			(*t_parsefunc)(t_printf_arg *);

typedef int			(*t_printfunc)(t_printf_arg *, char *format, va_list *);

typedef struct		s_printfn
{
	char			*types;
	t_printfunc		print;
}					t_printfn;

int					ft_printf_float(t_printf_arg *arg,
								char *format, va_list *args_p);

int					ft_printf_char(t_printf_arg *arg,
								char *format, va_list *args_p);

int					ft_printf_str(t_printf_arg *arg,
									char *format, va_list *args_p);

int					ft_printf_point(t_printf_arg *arg,
								char *format, va_list *args_p);

int					ft_printf_integer(t_printf_arg *arg,
									char *format, va_list *args_p);

int					ft_inttype(t_printf_arg *arg);

int					ft_zlen(t_printf_arg *arg);

int					ft_hlen(t_printf_arg *arg);

int					ft_hhlen(t_printf_arg *arg);

int					ft_llen(t_printf_arg *arg);

int					ft_dllen(t_printf_arg *arg);

int					ft_lllen(t_printf_arg *arg);

int					ft_strtype(t_printf_arg *arg);

int					ft_chartype(t_printf_arg *arg);

int					ft_pointtype(t_printf_arg *arg);

int					ft_floattype(t_printf_arg *arg);

#endif
