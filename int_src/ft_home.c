/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 13:14:49 by mmole             #+#    #+#             */
/*   Updated: 2014/03/26 15:29:11 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

int		ft_pcur(t_edit **lst)
{
	t_edit	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (!(tmp->video) && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > 0)
		return (i);
	return (0);
}

void	ft_home(t_edit **lst, struct winsize ws)
{
	int		pos;
	char	key[4];

	pos = ft_pcur(lst);
	key[0] = 27;
	key[1] = 91;
	key[2] = 68;
	key[3] = 0;
	while ((pos) >= 0)
	{
		ft_arrow_left_right(lst, key, ws);
		pos--;
	}
}

void	ft_end(t_edit **lst, struct winsize ws)
{
	int		pos;
	char	key[4];
	t_edit	*tmp;
	int		max;

	max = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		max++;
	}
	pos = ft_pcur(lst);
	key[0] = 27;
	key[1] = 91;
	key[2] = 67;
	key[3] = 0;
	while ((pos) < max)
	{
		ft_arrow_left_right(lst, key, ws);
		pos++;
	}
}
