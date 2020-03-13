/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:39:09 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:39:15 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	const char		*src1;

	dest1 = dest;
	src1 = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n > i)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
