/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:06:15 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:39:41 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = s;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (s1);
}
