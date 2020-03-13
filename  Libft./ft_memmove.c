/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 21:28:40 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 19:10:16 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *source;
	char *dest;

	source = (char *)src;
	dest = dst;
	if (!dest && !source)
		return (0);
	if (dest < source)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		dest[len - 1] = source[len - 1];
		len--;
	}
	return (dst);
}
