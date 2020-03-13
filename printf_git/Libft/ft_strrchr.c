/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:33:27 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:43:04 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a] != '\0')
		a++;
	while (s[a] != c && a != 0)
		a--;
	if (s[a] == c)
		return ((char *)&s[a]);
	return (NULL);
}
