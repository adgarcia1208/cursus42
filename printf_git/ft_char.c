/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:34:02 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/02 08:01:40 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(t_var_printf *t, int is_pourcent)
{
	const char c = is_pourcent ? '%' : (char)va_arg(t->ap, int);

	if (t->f_minus == 1)
	{
		write(1, &c, 1);
		t->ret++;
		if (t->size > 0)
			t->ret += print_repeated_char(' ', t->size - 1);
	}
	if (t->f_minus == 0)
	{
		if (t->size > 0)
			t->ret += print_repeated_char(' ', t->size - 1);
		write(1, &c, 1);
		t->ret++;
	}
	return (0);
}
