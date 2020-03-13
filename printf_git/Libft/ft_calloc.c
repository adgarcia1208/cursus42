/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:35:17 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:35:21 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
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
