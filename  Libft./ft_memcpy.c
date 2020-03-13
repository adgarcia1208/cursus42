/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:31:26 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 17:49:25 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
