/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:12:59 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 14:23:57 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"
#include "libft.h"
#include "header.h"

static	void	ft_save_some_env_values(t_data *data, char **env)
{
	data->env = ft_env_copy(env);
	data->home = getenv("HOME");
	data->old_pwd = getenv("OLD_PWD");
	data->pwd = getenv("PWD");
	data->path = getenv("PATH");
}

int				main(int argc, char **argv, char **env)
{
	t_env		*environ;
	int			debug;
	t_data		envi;

	ft_save_some_env_values(&envi, env);
	debug = 0;
	(void)argv;
	if (argc > 1)
		return (0);
	if (!env)
	{
		ft_putstr_fd("laucnhing a shell whitout an env is dangerous", 2);
		return (-4);
	}
	if (ft_termios(&environ, envi.env) == -1)
		return (-5);
	debug = ft_read(&environ, &envi);
	if (debug == -1)
		return (-1);
	else if (debug == -2)
		return (-2);
	else if (debug == -3)
		return (-3);
	return (0);
}
