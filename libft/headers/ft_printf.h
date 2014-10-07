/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:31:48 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 21:23:00 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "ft_readarg.h"

int		ft_printarg(t_printf_arg arg, char *format, va_list *args_p);

int		ft_writearg(int *index_p, char *format, va_list *args_p);

int		ft_printf(char *format, ...);

#endif
