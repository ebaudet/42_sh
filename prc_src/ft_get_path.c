/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 18:41:50 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/17 18:42:19 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_get_path(char **tabs)
{
	char	**path;
	char	**tmp;
	int		i;
	int		j;
	int		k;

	k = -1;
	while (tab[++k])
		if (ft_strncmp(tabs[k], "PATH", 4) == 0)
			break ;
	tmp = ft_strsplit(tabs[k] + 5, ':');
	i = ft_count_c(tabs[k], ':') + 1;
	path = (char **)malloc((i + 2) * sizeof(*path));
	path[i + 1] = 0;
	j = 0;
	while (j < i)
	{
		path[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		j++;
	}
	free(tmp);
	return (path);
}
