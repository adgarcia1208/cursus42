/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 16:14:57 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:50:14 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

static void		print_int(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	long n2;

	n2 = n;
	if (n2 < 0)
	{
		write(fd, "-", 1);
		n2 = n2 * -1;
	}
	if (n2 > 9)
		ft_putnbr_fd(n2 / 10, fd);
	print_int(n2 % 10 + 48, fd);
}
