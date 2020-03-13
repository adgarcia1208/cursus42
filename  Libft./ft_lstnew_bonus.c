/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 16:58:38 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 16:58:41 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
