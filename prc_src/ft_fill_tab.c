/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:34:27 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/26 16:38:16 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prc.h"

static char		*find_word(char *str, int *i)
{
	int		j;
	int		k;
	char	*ret;

	j = 0;
	k = *i;
	while (str[k] != '\0' && !is_space(str[k]))
	{
		k++;
		j++;
	}
	ret = (char *)malloc((j + 1) * sizeof(char));
	ret[j] = '\0';
	j = 0;
	while (*i < k)
	{
		ret[j] = str[*i];
		j++;
		*i += 1;
	}
	*i += 1;
	return (ret);
}

char			**ft_fill_tab(char *str, int size)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc((size + 1) * sizeof(char *));
	arr[size] = '\0';
	while (i < size)
	{
		arr[i] = find_word(str, &j);
		i++;
	}
	return (arr);
}
