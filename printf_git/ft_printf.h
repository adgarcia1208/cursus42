/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgarcia <adgarcia@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:28:31 by adgarcia          #+#    #+#             */
/*   Updated: 2020/03/06 22:40:52 by adgarcia         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int					ft_printf(const char *s, ...) __attribute__
((format(printf,1,2)));
typedef struct		s_var_printf
{
	va_list			ap;
	int				index;
	int				f_minus;
	int				f_zero;
	int				f_wid;
	int				f_precis;
	int				len;
	int				size;
	int				presize;
	int				tempint;
	int				check;
	int				ret;
	int				temp;
	int				tempsize;
}					t_var_printf;
int					ft_printf(const char *s, ...);
int					ft_pars(t_var_printf *t, const char *s);
int					ft_signed(t_var_printf *t, long int a);
int					ft_unsigned(t_var_printf *t, unsigned int a, const char *s);
int					ft_str(t_var_printf *t, char *str);
int					ft_char(t_var_printf *t, int is_pourcent);
int					ft_ptr(t_var_printf *t, unsigned long u);

#endif
