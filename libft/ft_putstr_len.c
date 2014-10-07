/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:50:31 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/03 15:47:15 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr_len(char const *s, unsigned long len,
						unsigned long width, char fill)
{
	unsigned long	size;
	int				i;

	i = 0;
	if (!s)
		return (write(1, "(NULL)", 6 > len ? len : 6));
	size = ft_strlen(s);
	if (len > 0)
		size = size > len ? len : size;
	if (size < width)
	{
		while (size + i++ < width)
			ft_putchar(fill);
	}
	return (i - 1 + write(1, s, size));
}
