/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 23:57:17 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 20:30:49 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_alloc(char **line, char **stock)
{
	int	i;
	int ok;

	i = 0;
	ok = 0;
	while (*stock && (*stock)[i] != '\n' && (*stock)[i] != '\0')
		i++;
	*line = ft_substr(*stock, 0, i, 0);
	*stock = ft_substr(*stock, i + 1, (int)ft_strlen(*stock) - i - 1, 1);
	return (0);
}

int		ft_stock(int fd, char **line, char **stock, char *buffer)
{
	int		e;
	int		i;

	e = 0;
	i = 0;
	while (ft_strchr(*stock, '\n') == NULL &&
			((i = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[i] = '\0';
		*stock = ft_strfjoin(*stock, buffer, 1);
	}
	if (ft_strchr(*stock, '\n'))
		e = 1;
	ft_alloc(line, stock);
	if (e != 1)
		return (0);
	return (e);
}

int		get_next_line(int fd, char **line)
{
	static char		*stock;
	char			buffer[BUFFER_SIZE + 1];
	int				i;

	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	i = ft_stock(fd, line, &stock, buffer);
	return (i);
}
