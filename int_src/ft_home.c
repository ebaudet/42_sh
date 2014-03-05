/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 13:14:49 by mmole             #+#    #+#             */
/*   Updated: 2014/03/03 18:53:36 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

int		ft_poscurseur(t_edit **lst)
{
	t_edit	*tmp;
	int		i;
	int		Col;

	i = 0;
	Col = tgetnum("co");
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

void	ft_home(t_edit **lst)
{
	int		pos;
	char	key[4];

	pos = ft_poscurseur(lst);
	key[0] = 27;
	key[1] = 91;
	key[2] = 68;
	key[3] = 0;
	while ((pos) >= 0)
	{
		arrow_left_right(lst, key);
		pos--;
	}
}

void	ft_end(t_edit **lst)
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
	pos = ft_poscurseur(lst);
	key[0] = 27;
	key[1] = 91;
	key[2] = 67;
	key[3] = 0;
	while ((pos) < max)
	{
		arrow_left_right(lst, key);
		pos++;
	}
}
