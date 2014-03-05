/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:52:12 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/05 17:58:54 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

#include <stdio.h>

void		arrow_left_right(t_edit **lst, char *key)
{
	t_edit		*tmp;
	int			col;

	col = tgetnum("co");
	tmp = *lst;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (ARROW && key[2] == 68 && key[3] == 0 && tmp->video > -1)
	{
		if (tmp->video == 0)
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
	else if (ARROW && key[2] == 67 && key[3] == 0 && tmp->video > -1)
	{

		if ((ft_poscurseur(lst) + 3) == col) //v1
			ft_putchar('\n');
		else if (ft_poscurseur(lst) % col == 0 && ft_poscurseur(lst) >= (col * 2)) // v1
			printf("\n");
		if (tmp->video == 1 && tmp->next != NULL)
		{
			tmp->video = 0;
			tmp->next->video = 1;
			ft_tputs("nd");
		}
		else if (tmp->video == 1 && tmp->next == NULL)
		{
			tmp->video = 0;
			ft_tputs("nd");
		}
	}
}

static void		arrow_up_down(t_edit **lst, t_hist **hst, char *key)
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
}

int				ft_check_key(char *key, t_edit **lst_e, t_hist **hst)
{
	if (key)
	{
		if (ARROW && (key[2] == 68 || key[2] == 67) && key[3] == 0)
			arrow_left_right(lst_e, key);
		else if (ARROW && (key[2] == 66 || key[2] == 65) && key[3] == 0)
			arrow_up_down(lst_e, hst, key);
		else if (ARROW && key[2] == 51 && key[3] == 126)
		{
			ft_filled_lste("~", lst_e, hst);
			ft_tputs("rc");
			ft_tputs("ce");
			ft_print_lste(lst_e);
		}
		else if (key[0] == 127 && key[1] == 0 && key[2] == 0 && key[3] == 0)
			ft_del_keyword(lst_e, hst);
		else if (ft_isprint(*key))
		{
			ft_tputs("im");
			ft_tputs("ic");
			ft_putchar_fd(*key, STDIN_FILENO);
			ft_tputs("ei");
			ft_filled_lste(key, lst_e, hst);
		}
		else if (key[0] == 27 && key[1] == 91 && key[2] == 72)
			ft_home(lst_e);
		else if (key[0] == 27 && key[1] == 91 && key[2] == 70)
			ft_end(lst_e);
		else if (ARROW && SHIFT && key[4] == 50 && (key[5] == 68 || key[5] == 67))
			ft_shift(lst_e, key);
	}
	else
		return (-1);
	return (0);
}
