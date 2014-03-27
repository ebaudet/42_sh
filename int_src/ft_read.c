/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:41:59 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 21:22:41 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_minishell.h"
#include "libft.h"
#include <sys/ioctl.h>

static void		begin_read(t_hist **hst, t_edit **lst, char **env)
{
	(void)*lst;
	ft_create_hst(hst, env);
	ft_filled_lste("", lst, hst);
	ft_putstr_fd("$> ", STDIN_FILENO);
	ft_tputs("sc");
}

static void		clean_all(t_edit **lst_e, t_hist **hst)
{
	ft_clean_thist(hst);
	*lst_e = NULL;
	*hst = NULL;
}


static int		after_while(t_env **ev, t_data *en, t_edit **lst, t_hist **hst )
{
	if (ft_sigleton(0) == 3)
	{
		ft_sigleton(-1);
		ft_putchar('\n');
		ft_read(ev, en);
	}
	else
	{
		if (*lst)
			ft_jumprint(lst);
		ft_putchar('\n');
		if ((ft_write_on_file(lst, en->env)) == 0)
			ft_lexer(ft_creat_string(*lst), en);
		clean_all(lst, hst);
		ft_read(ev, en);
		return (1);
	}
	return (0);
}

static int		in_while(char **key, t_env **env, t_hist **hst, t_edit **lst)
{
	int		value;

	value = 0;
	ft_bzero(*key, 7);
	if ((value = ft_sigleton(0)) > 0)
		ft_signal(env, lst, value, hst);
	else
	{
		if (read(0, *key, 6) == -1)
			return (-1);
		if (ft_sigleton(0) == 0)
			ft_check_key(*key, lst, hst);
		if ((value = ft_sigleton(0)) == 3)
			ft_signal(env, lst, value, hst);
	}
	return (0);
}

int				ft_read(t_env **env, t_data *environ)
{
	t_hist		*hst;
	t_edit		*lst_e;
	char		*key;

	hst = NULL;
	lst_e = NULL;
	key = (char *)malloc(sizeof(char) * 7);
	ft_bzero(key, 7);
	begin_read(&hst, &lst_e, environ->env);
	while (!ENTER && ft_sigleton(0) != 3)
	{
		if (in_while(&key, env, &hst, &lst_e) == -1)
		{
			free(key);
			return (-2);
		}
	}
	if (after_while(env, environ, &lst_e, &hst) == 1)
	{
		free(key);
		return (0);
	}
	return (0);
}
