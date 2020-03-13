/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:37:59 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 08:14:21 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_signednotminuspres(t_var_printf *t, long a)
{
	t->size = a < 0 ? t->size - 1 : t->size;
	if (a < 0 && t->f_zero == 1 && write(1, "-", 1))
	{
		a = a * -1;
		t->ret++;
	}
	while (t->size > t->len)
	{
		if (t->f_zero != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		t->ret++;
		t->size--;
	}
	if (a < 0 && t->f_zero == 0 && write(1, "-", 1))
	{
		a = a * -1;
		t->ret++;
		t->size--;
	}
	t->ret += ft_putnbr_base(a, "0123456789");
	return (0);
}

int		ft_notminus(t_var_printf *t, long a)
{
	if (t->f_precis == 1 && t->presize == 0 && a == 0)
	{
		t->ret += print_repeated_char(' ', t->size);
		return (0);
	}
	if (t->f_precis != 0)
	{
		t->size = a < 0 ? t->size - 1 : t->size;
		t->size += 1;
		while ((--(t->size) > t->temp && t->size > t->len))
			t->ret += write(1, " ", 1);
		if (a < 0 && (write(1, "-", 1)))
		{
			a = a * -1;
			t->ret++;
		}
		while (t->temp > t->len && (write(1, "0", 1)))
			t->temp-- && t->ret++;
		t->ret += ft_putnbr_base(a, "0123456789");
	}
	if (t->f_precis == 0)
		ft_signednotminuspres(t, a);
	return (0);
}

int		ft_signedwid(t_var_printf *t, long int a)
{
	if (t->f_precis == 1 && t->presize == 0 && a == 0)
	{
		t->ret += print_repeated_char(' ', t->size);
		return (0);
	}
	if (a == 0 && t->temp > t->len && t->size > t->temp)
	{
		t->ret += write(1, "0", 1);
		t->size-- && t->temp--;
	}
	while (t->temp > t->len)
	{
		t->ret += write(1, "0", 1);
		t->temp-- && t->size--;
	}
	while (t->temp >= t->size && t->temp > t->len)
		t->ret += write(1, "0", 1) && t->temp--;
	if (!(t->f_precis == 1 && t->presize == 0 && a == 0))
		t->ret += ft_putnbr_base(a, "0123456789");
	while (t->size > t->len && write(1, " ", 1))
	{
		t->ret++;
		t->size--;
	}
	return (0);
}

int		ft_minus(t_var_printf *t, long int a)
{
	if (a < 0)
	{
		write(1, "-", 1);
		a = a * -1;
		t->size--;
		t->ret++;
	}
	if (t->f_wid == 0)
	{
		while (t->temp > t->len)
		{
			write(1, "0", 1);
			t->ret++;
			t->temp--;
		}
		if (!(t->f_precis == 0 && t->presize == 0 && a == 0))
			t->ret += ft_putnbr_base(a, "0123456789");
		return (0);
	}
	if (t->f_wid == 1)
		ft_signedwid(t, a);
	return (0);
}

int		ft_signed(t_var_printf *t, long int a)
{
	t->len = ft_numlen_base(a, "0123456789");
	t->temp = t->presize;
	t->tempint = a;
	if (t->f_minus == 1)
		ft_minus(t, a);
	if (t->f_minus != 1)
		ft_notminus(t, a);
	return (0);
}
