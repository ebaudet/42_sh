/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_oplst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:33:56 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/28 21:55:23 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"

static t_op		*make_list_item(char *str, t_op *start)
{
	if (str[0] == ';')
		add_end(str, 0, start);
	else if (str[0] == '>' && str[1] == '>')
		add_end(str, 0, start);
	else if (str[0] == '<' && str[1] == '<')
		add_end(str, 0, start);
	else if (str[0] == '|' && str[1] == '|')
		add_end(str, 0, start);
	else if (str[0] == '&' && str[1] == '&')
		add_end(str, 0, start);
	else if (str[0] == '(')
		add_end(str, 0, start);
	else if (str[0] == ')')
		add_end(str, 0, start);
	else if (str[0] == '>')
		add_end(str, 0, start);
	else if (str[0] == '<')
		add_end(str, 0, start);
	else (str[0] == ';')
		add_end(str, 9, start);
}

t_op	*ft_make_oplst(char	*str)
{
	char	*s;
	char	**arr;
	t_op	*start;

	start = NULL;
	tmp = NULL;
	s = ft_strtrim(str);
	free(str);
	arr = ft_strsplit(s, ' ');
	free(s);
	while (*arr && *arr + 1)
	{
		make_list_item(*arr, start);

	}
}
