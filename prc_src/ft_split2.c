/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:16:07 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/05 13:48:01 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "prc.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		is_op(char c)
{
	if (c == '>' || c == '<' || c == '&' || c == '|' ||
		c == '(' || c == ')' || c == ';')
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
		{
			if (str[i] == ' ')
				j++;
			else
				j += 2;
			i++;
			if (is_op(str[i]))
				i++;
			while (str[i] == ' ' && !is_op(str[i]) && str[i] != '\0')
				i++;
		}
		else
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
	*i = j - k;
	k = 0;
	while (*i < j)
	{
		ret[k] = str[*i];
		k++;
		*i += 1;
	}
	while (str[*i] == ' ')
		*i = *i + 1;
	return (ret);
}

static char		*find_word(char *str, int *i)
{
	int			j;
	int			k;
	char		*ret;

	j = 0;
	k = *i;
	if (!is_op(str[*i]) && str[*i] != ' ')
	{
		while (!is_op(str[*i]) && str[*i] != ' ' && str[*i] != '\0')
			*i = *i + 1;
		j += *i;
		ret = (char *)malloc(sizeof(char) * (j + 1));
		ret[j] = '\0';
		j = 0;
		while (k < *i)
		{
			ret[j] = str[k];
			j++;
			k++;
		}
		while (str[*i] == ' ')
			*i = *i + 1;
		return (ret);
	}
	else
		return(find_word_2(str, i));
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = count_malloc(str);
	j = 0;
	k = 0;
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	arr[i] = '\0';
	while (j < i)
	{
		arr[j] = find_word(str, &k);
		j++;
	}
	return (arr);
}
