/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:24:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/28 19:27:45 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL3_H
# define FT_MINISHELL3_H

/*ft_lexer.c*/

typedef struct			s_tree
{
	struct s_tree		*parent;
	struct s_tree		*left;
	struct s_tree		*right;
	char				*str;
	int					code;
}						t_tree;

typedef struct			s_op
{
	char				*str;
	struct s_op			*next;
	int					code;
}						t_op;

int		ft_lexer(char *str);
t_op	*ft_make_oplst(char	*str);
void	ft_ecex(t_tree *tree);

#endif
