/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:52:12 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:27:38 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

static void		arrow_left_right(t_edit **lst, char *key)
{
	t_edit		*tmp;

	tmp = *lst;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (ARROW && key[2] == 68 && key[3] == 0 && tmp != *lst && tmp->prev->c)
	{
		if (tmp->video == 0 && tmp->c)
		{
			tmp->video = 1;
			ft_tputs("le");
		}
		else if (tmp->prev != NULL && tmp->c)
		{
			tmp->video = 0;
			tmp->prev->video = 1;
			ft_tputs("le");
		}
	}
	else if (ARROW && key[2] == 67 && key[3] == 0)
	{
		if (tmp->video == 1 && tmp->next == NULL)
		{
			tmp->video = 0;
			ft_tputs("nd");
		}
		else if (tmp->video == 1 && tmp->next != NULL)
		{
			tmp->video = 0;
			tmp->next->video = 1;
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
		ft_tputs("rc");
		ft_tputs("ce");
		ft_print_lste(lst);

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
		ft_tputs("rc");
		ft_tputs("ce");
		ft_print_lste(lst);

			}
		}
/*		ft_tputs("rc");
		ft_tputs("ce");
		ft_print_lste(lst);*/
	}
}

static void		del_keyword(t_edit **lst)
{
	t_edit		*tmp;

	tmp = NULL;
	if (!*lst)
		return ;
	tmp = *lst;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		ft_tputs("le");
		ft_tputs("dc");
		tmp->c = '\0';
		tmp->video = 0;
		if (tmp->prev)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		else
		{
			tmp->prev = NULL;
			tmp->next->prev = NULL;
			tmp->next = NULL;
		}
		free(tmp);
	}
	else if (tmp->prev == NULL && tmp->c != '\0')
	{
		tmp->c = '\0';
		ft_tputs("le");
		ft_tputs("dc");
		tmp->video = 0;
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
			del_keyword(lst_e);
		else if (ft_isprint(*key))
		{
			ft_filled_lste(key, lst_e, hst);
			ft_tputs("rc");
			ft_tputs("ce");
			ft_print_lste(lst_e);
		}
	}
	else
		return (-1);
	return (0);
}
