/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:52:12 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/17 13:17:13 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>
#include "ft_minishell.h"
#include "libft.h"
#include <sys/ioctl.h>

void	arrow_left_right(t_edit **lst, char *key, struct winsize ws)
{
	t_edit		*tmp;
	int			i;

	tmp = *lst;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (ARROW && ARROW_LEFT && tmp->video > -1)
	{
		if (tmp->video == 0 && ((ft_poscurseur(lst) + 4) % ws.ws_col) == 0)
		{
			tmp->video = 1;
			ft_tputs("up");
			i = -1;
			while (++i < ws.ws_col)
				ft_tputs("nd");
		}
		else if (tmp->video == 0)
		{				
			tmp->video = 1;
			ft_tputs("le");
		}
		else if (tmp->video == 1 && tmp->prev != NULL)
		{
			tmp->video = 0;
			tmp->prev->video = 1;
			ft_tputs("le");
		}
	}
	else if (ARROW && ARROW_RIGHT && tmp->video > -1)
	{
		if (tmp->video == 1 && ((ft_poscurseur(lst) + 4) % ws.ws_col) == 0)
		{
			tmp->video = 0;
			if (tmp->next != NULL)
			{
				tmp->next->video = 1;
			}
			ft_tputs("do");
		}
		else if (tmp->video == 1)
		{
			tmp->video = 0;
			if (tmp->next != NULL)
				tmp->next->video = 1;
			ft_tputs("nd");
		}
	}
}

void	arrow_up_down(t_edit **lst, t_hist **hst, char *key, struct winsize ws)
{
	t_hist		*tmp;

	tmp = NULL;
	if (*hst)
	{
		tmp = *hst;
		if (ARROW && key[2] == 65 && key[3] == 0)
		{
			tmp = *hst;
			while (tmp->next != NULL && tmp->valid == 0)
				tmp = tmp->next;
			if (tmp->next != NULL)
			{
				*lst = tmp->next->ptr;
				tmp->next->valid = 1;
				tmp->valid = 0;
			}
		}
		else
		{
			tmp = *hst;
			while (tmp->next != NULL && tmp->valid == 0)
				tmp = tmp->next;
			if (tmp->prev != NULL)
			{
				*lst = tmp->prev->ptr;
				tmp->valid = 0;
				tmp->prev->valid = 1;
			}
		}
		ft_tputs("rc");
		ft_tputs("cd");
		ft_print_lste(lst);
	}
	if (((ft_poscurseur(lst) + 4) % ws.ws_col) == 0)
		ft_tputs("do");
}

int		lengh_list(t_edit **lst_e)
{
	int		lengh;
	t_edit	*tmp;

	lengh = 0;
	tmp = *lst_e;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		lengh++;
	}
	return (lengh);
}

int		position_cursor(t_edit **lst_e)
{
	int		position;
	t_edit	*tmp;

	position = 0;
	tmp = *lst_e;
	while (tmp != NULL && tmp->video != 1)
	{
		tmp = tmp->next;
		position++;
	}
	return (position);
}

int		add_new_char(char *key, t_edit **lst_e, t_hist **hst, struct winsize ws)
{
	ft_filled_lste(key, lst_e, hst);
	print_commande(lst_e, ws);
	return (0);
}

void	get_winsize(struct winsize *ws)
{
	ioctl(1, TIOCGWINSZ, ws);
}

int		ft_check_key(char *key, t_edit **lst_e, t_hist **hst)
{
	struct winsize	ws;

	get_winsize(&ws);
	if (key)
	{
		if (ARROW && (ARROW_LEFT || ARROW_RIGHT))
			arrow_left_right(lst_e, key, ws);
		else if (ARROW && (ARROW_UP || ARROW_DOWN))
			arrow_up_down(lst_e, hst, key, ws);
		else if (ARROW && DELETE_R)
		{
			ft_filled_lste("~", lst_e, hst);
			ft_tputs("rc"); /* Restaurer la position enregistrée du curseur */
			/*ft_tputs("ce");*/ /* Effacer jusqu’à la fin de la ligne */
			ft_tputs("cd"); /* Effacer jusqu’à la fin de l’écran */
			ft_print_lste(lst_e);
		}
		else if (DELETE)
			ft_del_keyword(lst_e, hst, ws);
		else if (ft_isprint(*key))
			add_new_char(key, lst_e, hst, ws);
		else if (KEY_HOME)
			ft_home(lst_e, ws);
		else if (KEY_END)
			ft_end(lst_e, ws);
		else if (ARROW && SHIFT && key[4] == 50 && (key[5] == 68 || key[5] == 67))
			ft_shift(lst_e, key, ws);
	}
	else
		return (-1);
	return (0);
}
