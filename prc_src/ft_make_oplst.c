/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_oplst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:33:56 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/04 15:02:16 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void		add_end(char *str, int code, t_op **start)
{
	t_op	*tmp;

	tmp = *start;
	if (!*start)
	{
		*start = (t_op *)malloc(sizeof(t_op));
		(*start)->str = ft_strdup(str);
		(*start)->code = code;
		(*start)->next = NULL;
		(*start)->prev = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_op *)malloc(sizeof(t_op));
		tmp->next->str = ft_strdup(str);
		tmp->next->code = code;
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
}

static void		make_list_item(char *str, t_op **start)
{
	if (str[0] == ';')
		add_end(str, 0, start);
	else if (str[0] == '>' && str[1] == '>')
		add_end(str, 9, start);
	else if (str[0] == '<' && str[1] == '<')
		add_end(str, 7, start);
	else if (str[0] == '|' && str[1] == '|')
		add_end(str, 4, start);
	else if (str[0] == '&' && str[1] == '&')
		add_end(str, 3, start);
	else if (str[0] == '(')
		add_end(str, 1, start);
	else if (str[0] == ')')
		add_end(str, 2, start);
	else if (str[0] == '>')
		add_end(str, 8, start);
	else if (str[0] == '<')
		add_end(str, 6, start);
	else if (str[0] == '|')
		add_end(str, 5, start);
	else
		add_end(str, 10, start);
}

t_op			*ft_make_oplst(char	*str)
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
	return (start);
}
