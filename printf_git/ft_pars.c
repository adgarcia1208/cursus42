/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:56:39 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:59:31 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pres(t_var_printf *t, const char *s)
{
	if (s[t->index] == '.' && t->f_precis != 1)
	{
		t->f_precis++;
		t->index++;
	}
	if ((ft_isdigit(s[t->index])) == 1 && t->f_precis == 1)
	{
		t->presize = ft_atoi(s + t->index);
		while (ft_isdigit(s[t->index]) == 1)
			t->index++;
	}
	else if (s[t->index] == '*' && t->f_precis == 1)
	{
		t->presize = va_arg(t->ap, int);
		t->index++;
	}
	return (0);
}

int		ft_width(t_var_printf *t, const char *s)
{
	if ((ft_isdigit(s[t->index])) == 1 && t->f_precis == 0)
	{
		t->f_wid++;
		t->size = ft_atoi(s + t->index);
		while (ft_isdigit(s[t->index]) == 1)
			t->index++;
	}
	if (s[t->index] == '*' && t->f_precis == 0)
	{
		t->f_wid++;
		t->size = va_arg(t->ap, int);
		t->index++;
	}
	ft_pres(t, s);
	return (0);
}

int		ft_pars(t_var_printf *t, const char *s)
{
	while (s[t->index] == '0' || s[t->index] == '-')
	{
		if (s[t->index] == '0' && t->f_zero != 1)
			t->f_zero++;
		if (s[t->index] == '-' && t->f_minus != 1)
			t->f_minus++;
		t->index++;
	}
	ft_width(t, s);
	if (t->presize < 0)
		t->f_precis = 0;
	if (t->size < 0)
	{
		t->size = t->size * -1;
		t->f_minus = 1;
	}
	return (0);
}
