/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:40:26 by mmole             #+#    #+#             */
/*   Updated: 2014/03/26 15:01:53 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

static void	ft_next_left(t_edit *tmp, int cmp, char *key, t_edit **lst, struct winsize ws)
{
	while ((tmp->c == ' ' || tmp->c == '\t') && tmp->prev)
	{
		tmp = tmp->prev;
		cmp++;
	}
	while (tmp->prev && (tmp->prev->c != ' ' && tmp->prev->c != '\t'))
	{
		tmp = tmp->prev;
		cmp++;
	}
	while (cmp != 0)
	{
		ft_arrow_left_right(lst, key, ws);
		cmp--;
	}
}

static void	ft_shift_left(int pos, t_edit **lst, char *key, struct winsize ws)
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
	if (!tmp->next)
		cmp++;
	if ((tmp->c != ' ' || tmp->c != '\t') && tmp->prev)
	{
		tmp = tmp->prev;
		cmp++;
	}
	ft_next_left(tmp, cmp, key, lst, ws);
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

	pos = ft_poscurseur(lst);
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
