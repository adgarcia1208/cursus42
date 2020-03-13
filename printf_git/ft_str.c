/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:01:55 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:53:34 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sisnotminuspre(t_var_printf *t, char *str)
{
	if (t->len <= t->temp)
	{
		if (t->size - t->len > 0)
			t->ret += print_repeated_char(' ', t->size - t->len);
		ft_putstr_fd(str, 1);
		t->size -= t->len;
		t->ret += t->len;
	}
	if (t->len > t->temp)
	{
		if (t->size - t->temp > 0)
			t->ret += print_repeated_char(' ', t->size - t->temp);
		while (t->tempint < t->temp && str[t->tempint] != '\0')
		{
			write(1, &str[t->tempint], 1);
			t->tempint++;
			t->ret++;
		}
	}
	return (0);
}

int		ft_sisnotminus(t_var_printf *t, char *str)
{
	if (t->f_precis == 0)
	{
		t->ret += t->len;
		t->size -= t->len;
		if (t->size > 0)
			t->ret += print_repeated_char(' ', t->size);
		ft_putstr_fd(str, 1);
	}
	if (t->f_precis == 1)
		ft_sisnotminuspre(t, str);
	return (0);
}

int		ft_isminus(t_var_printf *t, char *str)
{
	if (t->f_precis == 0)
	{
		ft_putstr_fd(str, 1);
		t->ret += t->len;
		t->size -= t->len;
		if (t->size > 0)
			t->ret += print_repeated_char(' ', t->size);
	}
	if (t->f_precis == 1)
	{
		while (t->tempint < t->temp && str[t->tempint] != '\0')
		{
			write(1, &str[t->tempint], 1);
			t->tempint++;
			t->size--;
			t->ret++;
		}
		if (t->size > 0)
			t->ret += print_repeated_char(' ', t->size);
	}
	return (0);
}

int		ft_str(t_var_printf *t, char *str)
{
	t->len = ft_strlen(str);
	t->temp = t->presize;
	t->tempsize = t->size;
	if (t->f_minus != 0)
		ft_isminus(t, str);
	if (t->f_minus == 0)
		ft_sisnotminus(t, str);
	return (0);
}
