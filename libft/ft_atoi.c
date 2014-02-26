/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:29:21 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/12/01 20:47:49 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_white_spaces(char c)
{
	if (c == '\n' || c == '\r' || c == '\f' || c == 9 || c == '\v' || c == 32)
		return (1);
	else
		return (0);
}

static int		ft_calc(const char *str, int result, int i)
{
	while (str[i] != '\0' && (ft_isdigit(str[i]) == 1))
	{
		if ((str[i + 1] == '\0') || (ft_isdigit(str[i + 1]) == 0))
			result = (result + (str[i++] - 48));
		else
			result = ((result + (str[i++] - 48)) * 10);
	}
	return (result);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		stat;

	i = 0;
	result = 0;
	stat = 0;
	while (str[i] != '\0' && (ft_isdigit(str[i]) != 1))
	{
		if ((ft_white_spaces(*((char *)str + i))) == 1 && (stat == 0))
			i++;
		else if ((str[i] == '+' || str[i] == '-') && (stat == 0))
			stat = ++i;
		else
			return (0);
	}
	result = ft_calc(str, result, i);
	if (str[stat - 1] == '-')
		result *= -1;
	return (result);
}
