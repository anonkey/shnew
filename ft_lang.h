/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:21:00 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 10:50:21 by tseguier         ###   ########.fr       */
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
