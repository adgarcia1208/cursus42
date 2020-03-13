/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:19:11 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:42:58 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (s2[a] == '\0')
		return ((char *)s1);
	while (s1[i] && i != n)
	{
		while (s1[i + a] == s2[a] && s2[a] && (i + a) < n)
			a++;
		if (s2[a] == '\0')
			return ((char *)&s1[i]);
		else
		{
			i++;
			a = 0;
		}
	}
	return (0);
}
