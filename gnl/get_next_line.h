/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: adgarcia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 04:21:51 by adgarcia     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 20:20:48 by adgarcia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_substr(char *s, int start, int len, int f);
char		*ft_strfjoin(char *s1, char *s2, int f);
int			get_next_line(int fd, char **line);

#endif
