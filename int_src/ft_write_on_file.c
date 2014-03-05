/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_on_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:53:47 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/05 17:17:15 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/ft_minishell.h"

static int		check_lst(t_edit **lst)
{
	t_edit		*tmp;
	int			i;
	int			mark;

	mark = 0;
	tmp = *lst;
	i = 0;
	while (tmp->next && tmp->c != '\0')
	{
		if (tmp->c != ' ' && tmp->c != '\t')
			mark = 1;
		tmp = tmp->next;
	}
	if (mark != 1)
		return (-1);
	return (0);
}

static void		write_last_tmp(char c, int fd)
{
		write(fd, &c, 1);
		write(fd, "\n", 1);
}

int				ft_write_on_file(t_edit **lst)
{
	int			i;
	t_edit		*tmp;
	int			fd;

	i = 1;
	tmp = NULL;
	fd = open(FT_FILE, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (check_lst(lst) == -1)
		return (-2);
	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (tmp->c)
		{
			write(fd, &tmp->c, 1);
			i++;
		}
		tmp = tmp->next;
	}
	if (tmp->c)
		write_last_tmp(tmp->c, fd);
	close(fd);
	return (0);
}

