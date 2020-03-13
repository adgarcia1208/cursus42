/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:33:57 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 08:00:00 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptrnotminus(t_var_printf *t, unsigned long u)
{
	if (t->f_wid)
		t->size -= 2;
	if (t->size > 2)
	{
		if (u == 0 && t->f_precis == 1 && t->presize == 0)
			t->ret += write(1, " ", 1);
		while (t->size > t->len)
		{
			write(1, " ", 1);
			t->ret++;
			t->size--;
		}
	}
	t->ret += write(1, "0x", 2);
	if (!(u == 0 && t->f_precis == 1 && t->presize == 0))
		t->ret += ft_putnbr_base(u, "0123456789abcdef");
	return (0);
}

int		ft_ptrminus(t_var_printf *t, unsigned long u)
{
	t->ret += write(1, "0x", 2);
	if (t->f_wid)
		t->size -= 2;
	if (!(u == 0 && t->f_precis == 1 && t->presize == 0))
		t->ret += ft_putnbr_base(u, "0123456789abcdef");
	if (t->size > 2)
	{
		if (u == 0 && t->f_precis == 1 && t->presize == 0)
			t->ret += write(1, " ", 1);
		while (t->size > t->len)
		{
			write(1, " ", 1);
			t->ret++;
			t->size--;
		}
	}
	return (0);
}

int		ft_ptr(t_var_printf *t, unsigned long u)
{
	if ((long int)u < 0)
		u = ULONG_MAX;
	t->len = ft_numlen_base(u, "0123456789abcdef");
	if (t->f_minus == 1)
		ft_ptrminus(t, u);
	if (t->f_minus == 0)
		ft_ptrnotminus(t, u);
	return (0);
}
