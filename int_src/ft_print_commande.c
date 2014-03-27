/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_commande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 20:29:06 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/26 21:54:59 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "ft_minishell.h"
#include "libft.h"

int		last_list_selected(t_edit **lst_e)
{
	t_edit	*tmp;

	tmp = *lst_e;
	while (tmp != NULL)
	{
		if (tmp->video == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		print_commande(t_edit **lst_e, struct winsize ws)
{
	int		i;
	int		lengh;
	int		pos;

	lengh = l_list(lst_e);
	pos = position_cursor(lst_e);
	lengh += 4;
	i = 0;
	ft_tputs("rc");
	ft_tputs("cd");
	ft_print_lste(lst_e);
	if ((lengh % ws.ws_col) == 1)
		ft_tputs("nd");
	if ((lengh % ws.ws_col) == 1 && last_list_selected(lst_e) == 1)
		ft_tputs("do");
	return (0);
}
