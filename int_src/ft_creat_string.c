/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:19:23 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 21:22:45 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"

char		*ft_creat_string(t_edit *lst)
{
	int		i;
	t_edit	*tmp;
	char	*new;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	new = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		new[i] = tmp->c;
		tmp = tmp->next;
		i++;
	}
	new[i] = '\0';
	return (new);
}
