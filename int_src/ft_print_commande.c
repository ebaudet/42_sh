/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_commande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 20:29:06 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/12 20:29:06 by ebaudet          ###   ########.fr       */
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

int		print_commande(t_edit **lst_e)
{
	int		width;
	int		i;
	int		lengh;
	int		pos;

	lengh = lengh_list(lst_e);
	width = tgetnum("co");
	pos = position_cursor(lst_e);
	lengh += 4;
	i = 0;
	ft_tputs("rc"); /* Restaurer la position enregistrée du curseur */
	while (i < (lengh / width))
	{
		ft_tputs("dw"); /* Déplacer le curseur d’une ligne vers le haut */
		i++;
	}
	ft_tputs("cd"); /* Effacer jusqu’à la fin de l’écran */
	ft_print_lste(lst_e);
	if ((lengh % width) == 1)
		ft_tputs("nd");
	if ((lengh % width) == 1 && last_list_selected(lst_e) == 1)
		ft_tputs("do");
	return (0);
}
