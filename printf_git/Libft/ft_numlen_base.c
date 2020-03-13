/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:16:41 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:40:38 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen_base(long a, char *base)
{
	int len;
	int count;

	count = 1;
	len = ft_strlen(base);
	if (a < 0)
		a = a * -1;
	while (a >= len)
	{
		a = a / len;
		count++;
	}
	return (count);
}
