/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 02:55:56 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/04 14:05:20 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	if (!s)
		return (NULL);
	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		++s;
	}
	return (last);
}
