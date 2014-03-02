/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 11:22:27 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/02 17:34:30 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include "libft.h"

static int		is_op(char c)
{
	if (c == '>' || c == '<' || c == '&' || c == '|' || c == '(' || c == ')')
		return (1);
	else
		return (0);
}

static int		count_malloc(char * str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_op(str[i]) || str[i] == ' ')
			j++;
		i++;
		while (str[i] == ' ' || is_op(str[i]))
			i++;
	}
	return (j + 1);
}

static char		*find_word_2(char *str, int *i)
{
	int		j;
	int		k;
	char	*ret;

	j = *i;
	k = 0;
	while (str[j] == ' ')
		j++;
	while (is_op(str[j]))
	{
		k++;
		j++;
	}
	ret = (char *)malloc(sizeof(char) * (k + 1));
	ret[k] = '\0';
	*i += j - k;
	k = 0;
	while (*i <= j)
	{
		ret[k] = str[*i];
		k++;
		*i++;
	}
	return (ret);
}

static char		*find_word(char *str)
{
	static int	i = 0;
	int			j;
	int			k;
	char		*ret;

	j = 0;
	k = i;
	if (!is_op(str[i]) && str[i] != ' ')
	{
		while (!is_op(str[i]) && str[i] != ' ' && str[i] != '\0')
			j++;
		i += j;
		ret = (char *)malloc(sizeof(char) * (j + 1));
		ret[j] = '\0';
		j = 0;
		while (k < i)
		{
			ret[j] = str[k];
			j++;
			k++;
		}
		return (ret);
	}
	else
		return(find_word_2(str, &i));
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**arr;

	i = count_malloc(str);
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	arr[i] = '\0';
	while (j < i)
	{
		arr[j] = find_word(str);
		j++;
	}
	return (arr);
}
