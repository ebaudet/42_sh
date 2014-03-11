/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 09:42:54 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/11 12:24:03 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	size_argv(t_tree *tree)
{
	int		i;
	t_tree	*tmp;

	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->left;
	}
	return (i);
}

static char		**make_argv(t_tree *tree)
{
	t_tree *tmp;
	int		i;

	i = 0;
	tmp = tree;
	i = size_argv(tmp);
	if ((argv = (char **)malloc((i + 1) * sizeof(char *))))
	{
		argv[i] = '\0';
		i = 0;
		while (tmp)
		{
			argv[i] = tmp->str;
			i++;
			tmp = tmp->next;
		}
	}
}

int			ft_exec(t_tree **tree, char **env)
{
	char	**argv;
	t_tree	*tmp;

	i = 0;
	argv = NULL;
	*argv = NULL;
	if (IS_PIPE)
		ft_is_pipe(tree, env);
	else if (IS_REDIR)
		ret = ft_is_red(tree, env);
	else if (IS_OPERATOR)
		ret = ft_is_op(tree, env);
	else if (IS_WORD)
	{
		tmp = *tree;
		argv = make_argv(tmp);
		if ((ret = ft_builtin((*tree)->str, argv, env) != -1))
			return (ret);
		else
			ft_excecve((*tree)->str,argv, env);
	}
}
