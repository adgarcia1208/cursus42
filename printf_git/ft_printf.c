/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:33:31 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 07:57:36 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert(t_var_printf *t, const char *s)
{
	char	*temp;

	if (s[t->index] == 'i' || s[t->index] == 'd')
		ft_signed(t, (long)va_arg(t->ap, int));
	else if (s[t->index] == 'u' || s[t->index] == 'x' || s[t->index] == 'X')
		ft_unsigned(t, va_arg(t->ap, unsigned int), s);
	else if (s[t->index] == 'c' || s[t->index] == '%')
		s[t->index] == 'c' ? ft_char(t, 0) : ft_char(t, 1);
	else if (s[t->index] == 's')
	{
		temp = va_arg(t->ap, char *);
		ft_str(t, !temp ? "(null)" : temp);
	}
	else if (s[t->index] == 'p')
		ft_ptr(t, (long long)va_arg(t->ap, void *));
	return (0);
}

void	ft_reinit(t_var_printf *t)
{
	t->f_minus = 0;
	t->f_zero = 0;
	t->f_wid = 0;
	t->f_precis = 0;
	t->size = 0;
	t->presize = 0;
	t->len = 0;
	t->temp = 0;
	t->tempint = 0;
	t->tempsize = 0;
}

void	ft_init(t_var_printf *t)
{
	t->index = 0;
	t->f_minus = 0;
	t->f_zero = 0;
	t->f_wid = 0;
	t->f_precis = 0;
	t->size = 0;
	t->presize = 0;
	t->len = 0;
	t->temp = 0;
	t->ret = 0;
	t->tempint = 0;
	t->tempsize = 0;
}

int		ft_printf(const char *s, ...)
{
	t_var_printf	t;

	ft_init(&t);
	va_start(t.ap, s);
	while (s[t.index] != '\0')
	{
		while (s[t.index] != '%')
		{
			write(1, &s[t.index], 1);
			t.index++;
			t.ret++;
			if (s[t.index] == '\0')
				return (t.ret);
		}
		t.index++;
		ft_pars(&t, s);
		ft_convert(&t, s);
		ft_reinit(&t);
		t.index++;
	}
	va_end(t.ap);
	return (t.ret);
}
