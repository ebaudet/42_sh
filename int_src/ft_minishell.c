/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:12:59 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/11 14:51:35 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"
#include "libft.h"
#include "header.h"

int		main(int argc, char **argv, char **env)
{
	t_env		*environ;
	int			debug;

	debug = 0;
	(void)argv;
	if (argc > 1)
		return (0);
	if (!env)
		return (-4);
	if (ft_termios(&environ, env) == -1)
		return (-5);
	debug = ft_read(&environ, environ->env);
	if (debug == -1)
		return (-1);
	else if (debug == -2)
		return (-2);
	else if (debug == -3)
		return (-3);
	return (0);
}
