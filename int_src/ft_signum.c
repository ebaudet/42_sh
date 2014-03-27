/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:30:19 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:05 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include "ft_minishell.h"

static void		send_key(int key)
{
	char		cp[2];

	cp[0] = key;
	cp[1] = '\0';
	ioctl(0, TIOCSTI, cp);
}

void			ft_signum(int sig)
{
	int		value;

	if (sig == SIGTSTP)
	{
		value = ft_sigleton(1);
		send_key(-62);
	}
	else if (sig == SIGCONT)
		value = ft_sigleton(2);
	else if (sig == SIGINT)
	{
		value = ft_sigleton(3);
		send_key(-62);
	}
	else if (sig == SIGKILL || sig == SIGPIPE)
	{
		value = ft_sigleton(4);
		send_key(-62);
	}
}
