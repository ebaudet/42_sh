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
#include "libft.h"

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
		{
			mark = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (mark != 1)
		return (-1);
	return (0);
}

int				ft_write_on_file(t_edit **lst, char **env)
{
	t_edit		*tmp;
	int			fd;
	char		*file;

	tmp = *lst;
	file = ft_strjoin(ft_getenv(env, "HOME"), FT_FILE);
	if ((fd = open(file, O_WRONLY | O_APPEND)) == -1)
		return (-1);
	if (check_lst(lst) == -1)
		return (-2);
	while (tmp != NULL)
	{
		if (tmp->c)
			write(fd, &tmp->c, 1);
		tmp = tmp->next;
	}
	write(fd, "\n", 1);
	close(fd);
	free(file);
	return (0);
}
