/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:41:59 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/14 00:02:36 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"
#include "prc.h"

static void		begin_read(t_hist **hst, t_edit **lst)
{
	(void)*lst;
	ft_create_hst(hst);
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

static char		*ft_creat_string(t_edit *lst)
{
	int		i;
	t_edit	*tmp;
	char	*new;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	new = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		new[i] = tmp->c;
		tmp = tmp->next;
		i++;
	}
	new[i] = '\0';
	return (new);
}

int				ft_read(t_env **env, char **environ)
{
	t_hist		*hst;
	t_edit		*lst_e;
	char		key[7] = {0, 0, 0, 0, 0, 0, 0};

	hst = NULL;
	lst_e = NULL;
	begin_read(&hst, &lst_e);
	while (!ENTER)
	{
		ft_bzero(key, 7);
		if (read(0, key, 6) == -1)
			return (-2);
		ft_check_key(key, &lst_e, &hst);
	}
	if ((ft_write_on_file(&lst_e)) == 0)
		ft_lexer(ft_creat_string(lst_e), environ);
	clean_all(&lst_e, &hst);
	ft_putchar_fd('\n', STDIN_FILENO);
	ft_read(env, environ);
	return (0);
}
