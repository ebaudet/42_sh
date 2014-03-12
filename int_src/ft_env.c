/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 21:13:08 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/03 21:13:08 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"
#include "libft.h"

static int	ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

char		**ft_get_path(char **env)
{
	char	**path;
	char	**tmp;
	int		i;
	int		j;

	if ((tmp = ft_strsplit(ft_getenv(env, "PATH"), ':')) == NULL)
		return (NULL);
	i = ft_count_c(ft_getenv(env, "PATH"), ':') + 1;
	if ((path = (char **)malloc(i * sizeof(char *))) == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		if ((path[j] = ft_strjoin(tmp[j], "/")) == NULL)
			return (NULL);
		free(tmp[j]);
		j++;
	}
	path[i] = NULL;
	free(tmp);
	return (path);
}

char		*ft_getenv(char **env, char *name)
{
	int		i;
	char	loop;

	ft_putendl(name);
	ft_putnbr(ft_strlen(name));
	i = 0;
	loop = 'y';
	while (*(env + i) != NULL && loop == 'y')
	{
		if (ft_strncmp(*(env + i), name, ft_strlen(name)) == 0)
			loop = 'n';
		else
			i++;
	}
	ft_putnbr(i);
	if (loop == 'y')
		return (NULL);
	ft_putendl(*(env + i) + ft_strlen(name) + 1);
	return (*(env + i) + ft_strlen(name) + 1);
}
