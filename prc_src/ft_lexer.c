/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:21:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/12 14:21:47 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include <stdlib.h>
#include "libft.h"

static int	add_next_to_argv(t_op **lst)
{
	t_op	*tmp;
	t_op	*tmp2;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp->next->prior == 4 && i++)
		tmp = tmp->next;
	if (((*lst)->argv = (char **)malloc((i + 1) * sizeof(char *))))
	{
		(*lst)->argv[i] = '\0';
		i = -1;
		tmp = *lst;
		while (tmp->next && tmp->next->prior == 4)
		{
			(*lst)->argv[++i] = tmp->next->name;
			tmp2 = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp2;
		}
	}
	return (0);
}

static int		clean_list(t_op **lst)
{
	t_op	*tmp;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->prior == 3 || tmp->prior == 4)
		{
			if (tmp->next && tmp->next->code == COM)
				add_next_to_argv(&tmp);
		}
		tmp = tmp->next;
	}
	return (1);
}

int		ft_lexer(char *str, char **env)
{
	t_op	*lst;

	(void)env;
	lst = ft_make_oplst(str);
	if (!clean_list(&lst))
		return (0);
	return (1);
}
