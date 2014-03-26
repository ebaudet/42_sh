/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:36:42 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 15:37:22 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"

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
