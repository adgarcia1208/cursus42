/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 20:44:45 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:56:51 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_convert(int n, int e, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[e] = '\0';
	while (n >= 10)
	{
		str[e - 1] = n % 10 + '0';
		n = n / 10;
		e--;
	}
	str[e - 1] = n + '0';
	return (str);
}

static int		ft_count(int n)
{
	int count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		i;
	int		e;
	char	*str;

	i = 0;
	e = ft_count(n);
	if (n == -2147483648)
	{
		if (!(str = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * e + 1)))
		return (NULL);
	str = ft_convert(n, e, str);
	return (str);
}
