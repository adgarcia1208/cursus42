/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:51:00 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:36:35 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	else
		return (0);
}
