/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 18:22:46 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:59:57 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char			*ft_cpy(int a, int e, char const *s1, char *s2)
{
	int h;

	h = 0;
	while (e < a + 1)
	{
		s2[h] = s1[e];
		h++;
		e++;
	}
	s2[h] = '\0';
	return (s2);
}

static int			ft_cuttwo(char const *s1, char const *set, int i)
{
	int p;
	int	a;

	p = 0;
	a = i;
	while (i > 0)
	{
		while (set[p] != s1[a] && set[p])
			p++;
		if (set[p] == s1[a])
			a--;
		else
			return (a);
		i--;
		p = 0;
	}
	return (0);
}

static int			ft_cutone(char const *s1, char const *set)
{
	int p;
	int	e;
	int i;

	i = 0;
	p = 0;
	e = 0;
	while (s1[i])
	{
		while (set[p] != s1[e] && set[p])
			p++;
		if (set[p] == s1[e])
			e++;
		else
			return (e);
		i++;
		p = 0;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		a;
	int		e;
	char	*s2;

	e = ft_cutone(s1, set);
	i = ft_strlen(s1);
	a = ft_cuttwo(s1, set, i);
	if (a <= e)
		return (ft_strdup(""));
	if (!(s2 = ft_calloc(sizeof(char), (a - e) + 2)))
		return (NULL);
	s2 = ft_cpy(a, e, s1, s2);
	return (s2);
}
