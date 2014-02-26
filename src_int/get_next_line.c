/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:47:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:31:38 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

/*
** This function searches character \n or '\0' and copy the buffer.
*/
static int		ft_search_n(char **line, char *buf, char *rest)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
	{
		if  (i != 0)
			tmp = ft_strsub(buf, 0, i);
		else
			tmp = ft_strnew(0);
		ft_strcpy(rest, buf + i + 1);
		if (*line)
			*line = ft_strjoin(*line, tmp);
		else
			*line = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	if (*line)
		*line = ft_strjoin(*line, buf);
	else
		*line = ft_strdup(buf);
	return (0);
}

/*
** This function return the rest as the buf.
*/
static int		ft_end_string(char **line, char *rest)
{
	char		*tmp;

	tmp = ft_strnew(0);
	tmp = ft_strdup(rest);
	if (ft_search_n(line, tmp, rest) == 1)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

/*
** This function read the buf or rest if are.
*/
int				get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*rest;
	char			*buf;

	*line = ft_strnew(0);
	if (fd < 0)
		return (-1);
	if (rest)
	{
		if (ft_end_string(line, rest) == 1)
			return (1);
	}
	else
		rest = ft_strnew(BUF_SIZE);
	buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	ft_bzero(buf, BUF_SIZE + 1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_search_n(line, buf, rest) == 1)
			return (1);
	}
	free(buf);
	return (0);
}
