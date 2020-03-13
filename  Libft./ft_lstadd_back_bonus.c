/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 16:57:09 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 19:54:08 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (*alst && new)
	{
		temp = *alst;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = new;
	}
	else if (!(*alst))
		*alst = new;
}
