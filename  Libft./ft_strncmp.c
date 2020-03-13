/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 17:13:34 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 20:31:17 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
		while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
			i++;
	else
		return (0);
	return ((unsigned char)s1[i] - s2[i]);
}
