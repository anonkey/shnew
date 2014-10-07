/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcd_cell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 01:12:25 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/30 23:56:36 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LDCD_CELL_H
# define FT_LDCD_CELL_H
# include <stdlib.h>

typedef struct			s_ldcd_cell
{
	void				*content;
	size_t				content_size;
	struct s_ldcd_cell	*prev;
	struct s_ldcd_cell	*next;
}						t_slcd_cell;

typedef t_slcd_cell		*t_ldcd_cell;

t_ldcd_cell				ft_ldcd_cellnew(void *elem, size_t elem_size);

void					ft_ldcd_celldel(t_ldcd_cell *cell,
										void (*del)(void **));

#endif
