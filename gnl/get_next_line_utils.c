/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 02:58:55 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 01:42:42 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char		*ft_substr(char *s, int start, int len, int f)
{
	int		i;
	char	*st;

	i = 0;
	if (len < 0)
	{
		free(s);
		return (NULL);
	}
	if (!(st = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
		while (s[start] && i != len)
			st[i++] = s[start++];
	st[i] = '\0';
	if (f == 1)
		free(s);
	return (st);
}

char		*ft_strfjoin(char *s1, char *s2, int f)
{
	int		len;
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1 && s1[i])
		str[i++] = s1[a++];
	a = 0;
	while (s2[a])
		str[i++] = s2[a++];
	str[i] = '\0';
	if (f == 1)
		free(s1);
	return (str);
}
