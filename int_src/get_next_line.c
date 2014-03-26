/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:46:59 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/26 16:56:01 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_minishell.h"

static int	gnl_buf(char *buf, char *tmp, char **line)
{
	int		i;
	char	*tmp_line;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			tmp = ft_strcpy(tmp, (buf + i + 1));
			buf[i] = '\0';
			tmp_line = ft_strjoin(*line, buf);
			if (*line)
				ft_strdel(line);
			*line = tmp_line;
			return (1);
		}
		i++;
	}
	if (*line)
	{
		tmp_line = ft_strjoin(*line, buf);
		ft_strdel(line);
		*line = tmp_line;
	}
	return (0);
}

static int	gnl_tmp(char *tmp, char **line)
{
	int	i;

	i = 0;
	while ((tmp)[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			*line = ft_strdup(tmp);
			tmp = ft_strcpy(tmp, (tmp + i + 1));
			return (1);
		}
		i++;
	}
	return (0);
}

static int	gnl_end(int ret, char **line)
{
	if (ret == 0)
	{
		if ((*line)[0] != '\0')
			return (1);
		return (0);
	}
	return (-1);
}

int			get_next_line(int const fd, char **line)
{
	static char	tmp[BUFF_SIZE + 1];
	char		*buf;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (gnl_tmp(tmp, line) == 1)
		return (1);
	*line = ft_strdup(tmp);
	buf = (char *)malloc(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (gnl_buf(buf, tmp, line) == 1)
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	ft_strdel(&buf);
	tmp[0] = '\0';
	return (gnl_end(ret, line));
}
