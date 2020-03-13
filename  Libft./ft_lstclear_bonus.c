/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 18:51:22 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 19:42:07 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *temp2;

	if (*lst)
	{
		temp2 = *lst;
		while (temp2 != 0)
		{
			temp = temp2;
			temp2 = temp2->next;
			ft_lstdelone(temp, (*del));
		}
		*lst = NULL;
	}
}
