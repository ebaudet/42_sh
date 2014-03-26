/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:38:04 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 16:01:29 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"

int		l_list(t_edit **lst_e)
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
