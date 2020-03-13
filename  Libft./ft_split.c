/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 17:14:43 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 18:20:28 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **nwstr)
{
	int i;

	i = 0;
	while (nwstr[i])
	{
		free(nwstr[i]);
		i++;
	}
	return (nwstr);
}

static char		*ft_copysplit(int *i, char c, char const *s1)
{
	int		u;
	int		a;
	char	*str;

	u = 0;
	a = 0;
	while (s1[*i] == c)
		(*i)++;
	a = *i;
	while (s1[*i] != c && s1[*i] != '\0')
		(*i)++;
	if (!(str = (char *)malloc(sizeof(char) * (*i - a) + 1)))
		return (NULL);
	while (s1[a] != c && s1[a] != '\0')
		str[u++] = s1[a++];
	str[u] = '\0';
	return (str);
}

static int		ft_countword(char const *s1, char c)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (s1[i])
	{
		if (s1[i] != c && s1[i])
			a++;
		while (s1[i] != c && s1[i])
			i++;
		while (s1[i] == c && s1[i])
			i++;
	}
	return (a);
}

char			**ft_split(char const *s1, char c)
{
	int		h;
	int		i;
	int		word;
	char	**nwstr;

	h = 0;
	i = 0;
	word = ft_countword(s1, c);
	if (!(nwstr = ft_calloc(sizeof(char *), (word + 1))))
		return (NULL);
	while (h < word)
	{
		if ((nwstr[h] = ft_copysplit(&i, c, s1)) == NULL)
			return (ft_free(nwstr));
		h++;
	}
	return (nwstr);
}
