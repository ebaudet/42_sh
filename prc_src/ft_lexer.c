/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:21:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/05 16:09:23 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include <stdlib.h>
#include "libft.h"

int		ft_lexer(char *str)
{
	t_op	*lst;
//	t_tree	*tree;

	lst = ft_make_oplst(str);
	ft_putstr("\n");
	while (lst)
	{
		ft_putstr(lst->str);
		ft_putstr("\t");
		ft_putnbr(lst->code);
		ft_putstr("\n");
		lst = lst->next;
	}
//	tree = ft_make_tree(lst);
//	ft_exec(tree);
	return (0);
}
