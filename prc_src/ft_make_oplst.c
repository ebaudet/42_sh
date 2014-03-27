/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_oplst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:33:56 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/27 12:59:02 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "prc.h"
#include "libft.h"

static void		add_end_2(char *str, int prior, int code, t_op **start)
{
	t_op	*tmp;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_op *)malloc(sizeof(t_op));
	tmp->next->name = ft_strdup(str);
	tmp->next->code = code;
	tmp->next->prior = prior;
	tmp->next->next = NULL;
	tmp->next->top = NULL;
	tmp->next->lft = NULL;
	tmp->next->rgt = NULL;
	tmp->next->argv = NULL;
	tmp->next->stat = 0;
	tmp->next->nbr = 0;
}

static void		add_end(char *str, int prior, int code, t_op **start)
{
	if (!*start)
	{
		*start = (t_op *)malloc(sizeof(t_op));
		(*start)->name = ft_strdup(str);
		(*start)->code = code;
		(*start)->prior = prior;
		(*start)->next = NULL;
		(*start)->top = NULL;
		(*start)->lft = NULL;
		(*start)->rgt = NULL;
		(*start)->nbr = 0;
		(*start)->argv = NULL;
		(*start)->stat = 0;
	}
	else
		add_end_2(str, prior, code, start);
}

static void		make_list_item(char *str, t_op **start)
{
	if (str[0] == ';')
		add_end(str, 0, SEMICOL, start);
	else if (str[0] == '>' && str[1] == '>')
		add_end(str, 3, DB_AR_RIGHT, start);
	else if (str[0] == '|' && str[1] == '|')
		add_end(str, 1, OR, start);
	else if (str[0] == '&' && str[1] == '&')
		add_end(str, 1, AND, start);
	else if (str[0] == '>')
		add_end(str, 3, AR_RIGHT, start);
	else if (str[0] == '<' && str[1] != '<')
		add_end(str, 3, AR_LEFT, start);
	else if (str[0] == '|' && str[1] == '\0')
		add_end(str, 2, PIPE, start);
	else
		add_end(str, 4, COM, start);
}

t_op			*ft_make_oplst(char *str)
{
	char	*s;
	char	**arr;
	t_op	*start;
	int		i;

	i = 0;
	start = NULL;
	s = ft_strtrim(str);
	free(str);
	arr = ft_split(s);
	free(s);
	while (arr[i] != '\0')
	{
		make_list_item(arr[i], &start);
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	return (start);
}
