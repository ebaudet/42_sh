/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      :::::::::  */
/*   ft_filled_*lste.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 21:22:13 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:28:50 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/ft_minishell.h"

int		ft_filled_lste(char *key, t_edit **lst, t_hist **hst)
{
	t_hist		*new_hst;
	t_edit		*tmp;
	t_edit		*new;

	new_hst = NULL;
	tmp = NULL;
	new = (t_edit *)malloc(sizeof(t_edit));
	new->c = *key;
	if (!*lst)
	{
		if (*key)
		{
			new->c = *key;
			new->video = 0;
		}
		else
		{
			new->c = '\0';
			new->video = -1;
		}
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		new_hst = (t_hist *)malloc(sizeof(t_hist));
		new_hst->valid = 1;
		new_hst->ptr = new;
		new_hst->prev = NULL;
		new_hst->next = *hst;
		if (*hst)
			(*hst)->prev = new_hst;
		else
			new_hst->prev = NULL;
		*hst = new_hst;
	}
	else if ((*lst)->video == -1)
	{
		(*lst)->c = new->c;
		(*lst)->video = 0;
		free(new);
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL && tmp->video == 0)
			tmp = tmp->next;
		if (tmp->video == 0)
		{
			new->next = NULL;
			new->prev = tmp;
			tmp->next = new;
		}
		else
		{
			new->next = tmp;
			new->prev = tmp->prev;
			if (new->prev == NULL)
				*lst = new;
			else
				tmp->prev->next = new;
			tmp->prev = new;
		}
		new->video = 0;
	}
	return (0);
}

