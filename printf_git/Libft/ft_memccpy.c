/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:38:18 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:38:26 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	const char		*src1;

	i = 0;
	dest1 = dest;
	src1 = src;
	while (n > i && (unsigned char)src1[i] != (unsigned char)c)
	{
		dest1[i] = src1[i];
		i++;
	}
	if ((unsigned char)src1[i] == (unsigned char)c)
	{
		dest1[i] = src1[i];
		return (&dest1[i + 1]);
	}
	return (NULL);
}
