/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 00:57:22 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 18:21:31 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	char *str;

	if (!(str = malloc(size * nmemb)))
		return (0);
	ft_bzero(str, size * nmemb);
	return (str);
}
