/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 15:26:28 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 17:46:00 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_strlenv2(char const *s1, char const *s2, int i, int a)
{
	int len;

	len = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[a] != '\0')
		a++;
	len = a + i + 1;
	return (len);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlenv2(s1, s2, i, a);
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (s1[i])
		str[i++] = s1[a++];
	a = 0;
	while (s2[a])
		str[i++] = s2[a++];
	str[i] = '\0';
	return (str);
}
