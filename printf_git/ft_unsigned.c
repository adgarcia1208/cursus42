/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:31:49 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:45:53 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_base(t_var_printf *t, unsigned int a, const char *s)
{
	if (t->f_precis != 0 && t->presize == 0 && a == 0)
	{
		if (t->size == 1)
		{
			write(1, " ", 1);
			t->ret++;
		}
		return (0);
	}
	if (s[t->index] == 'u')
		t->ret += ft_putnbr_base(a, "0123456789");
	if (s[t->index] == 'x')
		t->ret += ft_putnbr_base(a, "0123456789abcdef");
	if (s[t->index] == 'X')
		t->ret += ft_putnbr_base(a, "0123456789ABCDEF");
	return (0);
}

int		ft_usignednotminuspres(t_var_printf *t, unsigned int a, const char *s)
{
	while (t->size > t->len)
	{
		if (t->f_zero != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		t->ret++;
		t->size--;
	}
	ft_base(t, a, s);
	return (0);
}

int		ft_unnotminus(t_var_printf *t, unsigned int a, const char *s)
{
	if (t->f_precis != 0)
	{
		while (t->size > t->temp && t->size > t->len)
		{
			write(1, " ", 1);
			t->size--;
			t->ret++;
		}
		while (t->temp > t->len)
		{
			write(1, "0", 1);
			t->temp--;
			t->ret++;
		}
		ft_base(t, a, s);
	}
	if (t->f_precis == 0)
		ft_usignednotminuspres(t, a, s);
	return (0);
}

int		ft_unsignedwid(t_var_printf *t, unsigned int a)
{
	if (t->f_precis != 0)
	{
		if (a == 0 && t->presize == 0)
			while ((t->size > t->temp && t->size > 0) && t->tempsize != 1)
			{
				write(1, " ", 1);
				t->size--;
				t->ret++;
			}
		while (t->size > t->temp && t->size > t->len)
		{
			write(1, " ", 1);
			t->size--;
			t->ret++;
		}
	}
	else
	{
		while (t->size > t->len)
		{
			t->ret += write(1, " ", 1);
			t->size--;
		}
	}
	return (0);
}

int		ft_unsigned(t_var_printf *t, unsigned int a, const char *s)
{
	s[t->index] == 'u' ? (t->len = ft_numlen_base(a, "0123456789")) :
		(t->len = ft_numlen_base(a, "0123456789abcdef"));
	t->temp = t->presize;
	t->tempsize = t->size;
	if ((int)a < 0 && (s[t->index] == 'x' || s[t->index] == 'X'))
		t->len = ft_numlen_base(INT32_MAX, "0123456789abcdef");
	if ((int)a < 0 && s[t->index] == 'u')
		t->len = ft_numlen_base(INT32_MAX, "0123456789");
	if (t->f_minus == 1)
	{
		if (t->f_precis != 0)
			while (t->temp > t->len)
			{
				write(1, "0", 1);
				t->temp--;
				t->size--;
				t->ret++;
			}
		ft_base(t, a, s);
		if (t->f_wid != 0)
			ft_unsignedwid(t, a);
		return (0);
	}
	ft_unnotminus(t, a, s);
	return (0);
}
