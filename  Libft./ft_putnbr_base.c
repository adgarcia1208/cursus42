/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/02 04:00:02 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:20:58 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_base(long int n, char *str)
{
	int count;
	int len;

	len = ft_strlen(str);
	count = 0;
	if (n < len)
	{
		write(1, &str[n], 1);
		count++;
	}
	if (n >= len)
	{
		count += ft_putnbr_base(n / len, str);
		count += ft_putnbr_base(n % len, str);
	}
	return (count);
}
