/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:42:19 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:43:15 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*st;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		if (!(st = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		st[i] = '\0';
		return (st);
	}
	if (!(st = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[start] && i != len)
		st[i++] = s[start++];
	st[i] = '\0';
	return (st);
}
