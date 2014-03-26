/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:40:26 by mmole             #+#    #+#             */
/*   Updated: 2014/03/26 16:58:12 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

static void	ft_n_lft(t_edit *tmp, t_help *help, t_edit **lst, struct winsize ws)
{
	while ((tmp->c == ' ' || tmp->c == '\t') && tmp->prev)
	{
		tmp = tmp->prev;
		help->cmp++;
	}
	while (tmp->prev && (tmp->prev->c != ' ' && tmp->prev->c != '\t'))
	{
		tmp = tmp->prev;
		help->cmp++;
	}
	while (help->cmp != 0)
	{
		ft_arrow_left_right(lst, help->key, ws);
		help->cmp--;
	}
}

static void	ft_shift_left(int pos, t_edit **lst, char *key, struct winsize ws)
{
	t_edit	*tmp;
	t_help	help;

	help.cmp = 0;
	help.key = key;
	tmp = *lst;
	while (tmp && tmp->next && pos != help.cmp)
	{
		tmp = tmp->next;
		help.cmp++;
	}
	help.cmp = 0;
	if (!tmp->next)
		help.cmp++;
	if ((tmp->c != ' ' || tmp->c != '\t') && tmp->prev)
	{
		tmp = tmp->prev;
		help.cmp++;
	}
	ft_n_lft(tmp, &help, lst, ws);
}

static void	ft_shift_right(int pos, t_edit **lst, char *key, struct winsize ws)
{
	t_edit	*tmp;
	int		cmp;

	cmp = 0;
	tmp = *lst;
	while (tmp && tmp->next && pos != cmp)
	{
		tmp = tmp->next;
		cmp++;
	}
	cmp = 0;
	while ((tmp->c != ' ' && tmp->c != '\t') && tmp->next)
	{
		tmp = tmp->next;
		cmp++;
	}
	while (tmp->next && (tmp->c == ' ' || tmp->c == '\t'))
	{
		tmp = tmp->next;
		cmp++;
	}
	while (cmp-- != 0)
		ft_arrow_left_right(lst, key, ws);
}

void		ft_shift(t_edit **lst, char *key, struct winsize ws)
{
	int	pos;

	pos = ft_pcur(lst);
	if (key[3] == 59 && key[4] == 50 && key[5] == 68)
	{
		key[0] = 27;
		key[1] = 91;
		key[2] = 68;
		key[3] = 0;
		ft_shift_left(pos, lst, key, ws);
	}
	else
	{
		key[0] = 27;
		key[1] = 91;
		key[2] = 67;
		key[3] = 0;
		ft_shift_right(pos, lst, key, ws);
	}
}
