/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:41:59 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:30:05 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

static int		write_on_file(t_edit **lst)
{
	int			i;
	t_edit		*tmp;
	int			fd;

	i = 1;
	tmp = NULL;
	fd = open(FT_FILE, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (!*lst)
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
	{
		write(fd, &tmp->c, 1);
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}

static char		*ini_key(char *key)
{
	key[0] = 0;
	key[1] = 0;
	key[2] = 0;
	key[3] = 0;
	return (key);
}

static void		clean_all(char **key, t_edit **lst_e, t_hist **hst)
{
	*key = ini_key(*key);
	free(*key);
	*key = NULL;
	ft_clean_thist(hst);
	*lst_e = NULL;
	*hst = NULL;
}

int				ft_read(t_env **env)
{
	t_hist		*hst;
	t_edit		*lst_e;
	char		*key;

	hst = NULL;
	lst_e = NULL;
	key = (char *)malloc(sizeof(char) * 4);
	if (!key)
		return (-1);
	key[4] = '\0';
	key = ini_key(key);
	ft_create_hst(&hst);
	ft_filled_lste("", &lst_e, &hst);
	ft_putstr_fd("$> ", STDIN_FILENO);
	ft_tputs("sc");
	while (!(key[0] == 10 && key[1] == 0 && key[2] == 0 && key[3] == 0))
	{
		key = ini_key(key);
		if (read(0, key, 4) == -1)
			return (-2);
		ft_check_key(key, &lst_e, &hst);
	}
	write_on_file(&lst_e);
	clean_all(&key, &lst_e, &hst);
	ft_putchar_fd('\n', STDIN_FILENO);
	ft_read(env);
	return (0);
}
