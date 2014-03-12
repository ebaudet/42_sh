/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:21:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/12 18:59:22 by wbeets           ###   ########.fr       */
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
	while (tmp->next && tmp->next->prior == 4)
	{
		i++;
		tmp = tmp->next;
	}
	if ( i != 0 && ((*lst)->argv = (char **)malloc((i + 1) * sizeof(char *))))
	{
		(*lst)->argv[i] = '\0';
		i = 0;
		tmp = *lst;
		while (tmp->next && tmp->next->prior == 4)
		{
			(*lst)->argv[i] = tmp->next->name;
			i++;
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

static int	check_list(t_op **lst)
{
	t_op	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->nbr = i;
		i++;
		if (tmp->code == AR_LEFT || tmp->code == AR_RIGHT
		|| tmp->code == DB_AR_RIGHT)
		{
			if (!tmp->argv)
			{
				ft_putstr_fd("error redirection error near ", 2);
				ft_putstr_fd(tmp->name, 2);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int		ft_lexer(char *str, char **env)
{
	t_op	*lst;
	t_op	*tree;
	int		i;

	i = 0;
	(void)env;
	lst = ft_make_oplst(str);
	clean_list(&lst);
	if (!check_list(&lst))
	{
		/*free list*/
		return (0);
	}
	tree = ft_create_tree(&lst);
	/*
	ft_putstr("\n");
	while (lst)
	{
		ft_putstr(lst->name);
		if (lst->argv)
		{
			ft_putstr(" \nin arg \t");
			while (lst->argv[i] != '\0')
			{
				ft_putstr(lst->argv[i++]);
			ft_putstr("\t");
			}
		}
		i = 0;
		lst= lst->next;
		ft_putstr("\n");
	}*/
	return (1);
}
