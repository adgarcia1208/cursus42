/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_repeated_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:18:02 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:40:44 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_repeated_char(char c, int a)
{
	int ret;

	ret = 0;
	while (a != 0)
	{
		write(1, &c, 1);
		a--;
		ret++;
	}
	return (ret);
}
