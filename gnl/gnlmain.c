/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gnlmain.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 07:51:29 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 20:20:16 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>



int	main(int ac, char **av)
{
	int		fd[ac - 1];
	int		i;
	char	*line;
	int		j;
	int		ret[ac - 1];

	line = 0;
	ret[0] = 0;
	ret[1] = 0;
	ac = (int)ac;
	av = (char**)av;
	j = 0;
	if (ac == 2)
		fd[0] = open(av[1], O_RDONLY);
	else if (ac == 3)
	{
		fd[0] = open(av[1], O_RDONLY);
		fd[1] = open(av[2], O_RDONLY);
	}
	else
		fd[0] = 0;
	dprintf(1, ">DEBUT DU AV[1]:<\n\n");
	while ((ret[0] = get_next_line(fd[0], &line)))
	{
		//dprintf(1, "ret[0]:%d\n", ret[0]);
		i = 0;
		if (ret[0] == -1)
		{
			free(line);
			return (0);
		}
		while (line[i])
		{
			write(1, &line[i], 1);
			i++;
		}
		if (ret[0] != 0)
			write(1, "\n", 1);
		else
		{
			j++;
			dprintf(1, "\t###PAS DE BACKFLASH n A LA FIN###\n");
		}
		j++;
		free(line);
	}
	i = 0;
	if (line && line[i])
	{
		while (line[i])
		{
			write(1, &line[i], 1);
			i++;
		}
		if (ret[0] != 0)
			write(1, "\n", 1);
		else 
		{
			j++;
			dprintf(1, "\t###PAS DE BACKFLASH n A LA FIN###\n");
		}
		free(line);
	}
	else
		free(line);
	dprintf(1, "\n>FIN DU AV[1]<\n");
	//	dprintf(1, "ret[0]=(0):%d\n", ret[0]);
	if (ac == 3)
	{
		dprintf(1, "\n>DEBUT DU AV[2]:<\n\n");
		while ((ret[1] = get_next_line(fd[1], &line)))
		{
			//dprintf(1, "ret[1]:%d\n", ret[1]);
			i = 0;
			if (ret[1] == -1)
			{
				free(line);
				return (0);
			}
			while (line[i])
			{
				write(1, &line[i], 1);
				i++;
			}
			if (ret[1] != 0)
				write(1, "\n", 1);
			else 
			{
				j++;
				dprintf(1, "\t###PAS DE BACKFLASH n A LA FIN###\n");
			}
			j++;
			free(line);
		}
		i = 0;
		if (line && line[i])
		{
			while (line[i])
			{
				write(1, &line[i], 1);
				i++;
			}
			if (ret[1] != 0)
				write(1, "\n", 1);
			else 
			{
				j++;
				dprintf(1, "\t###PAS DE BACKFLASH n A LA FIN###\n");
			}
			free(line);
		}
		else
			free(line);
		dprintf(1, "\n>FIN DU AV[2]<\n");
		//		dprintf(1, "ret[1]=(0):%d\n", ret[1]);

	}
	dprintf(1, "NB LINE= %d\n", j);
	return (0);
}
