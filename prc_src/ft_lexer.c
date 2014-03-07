/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:21:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/06 11:08:12 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include <stdlib.h>
#include "libft.h"

int		ft_lexer(char *str)
{
	t_op	*lst;
	t_tree	*tree;

	lst = ft_make_oplst(str);
	ft_putstr("\n");
	tree = ft_make_tree(lst);
	(void)tree;
//	ft_exec(tree);
	return (0);
}
