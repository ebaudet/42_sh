/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:16:30 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 20:29:29 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_minishell.h"
#include "libft.h"

static void		sig_tstp(t_env **env)
{
	char		cp[2];
	int			fd;

	cp[0] = (*env)->term.c_cc[VSUSP];
	cp[1] = '\0';
	fd = open(ttyname(0), O_RDWR);
	tcsetattr(fd, TCSANOW, &(*env)->term_cpy);
	signal(SIGTSTP, SIG_DFL);
	ioctl(fd, TIOCSTI, cp);
}

static void		sig_cont(t_env **env, t_edit **lst)
{
	int			fd;
	char		*term;

	(void)lst;
	fd = open(ttyname(0), O_RDWR);
	term = NULL;
	signal(SIGTSTP, ft_signum);
	(*env)->term.c_lflag &= ~(ECHO | ICANON);
	ft_sigleton(-1);
	tcsetattr(fd, TCSANOW, &(*env)->term);
	close(fd);
	ft_putstr("$> ");
	ft_print_lste(lst);
}

static void		sig_int(t_edit **lst)
{
	t_edit		*tmp2;
	t_edit		*tmp;

	tmp2 = *lst;
	tmp = *lst;
	while (tmp)
	{
		tmp->video = 0;
		tmp->c = '\0';
		tmp = tmp->next;
		tmp2->next = NULL;
		if (tmp2 != *lst)
			free(tmp2);
		tmp2 = tmp;
	}
}

void		ft_signal(t_env **env, t_edit **lst, int value, t_hist **hst)
{
	(void)hst;
	if (value == 1)
		sig_tstp(env);
	else if (value == 2)
		sig_cont(env, lst);
	else if (value == 3)
		sig_int(lst);
	else if (value == 4)
		exit(0);
}


