/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:33:47 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/12/01 19:53:36 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_mall_str(int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		return (str);
	}
	return (0);
}

static int		ft_nbr_char(int n)
{
	int		len;

	len = 0;
	if (n)
	{
		if (n < 0)
		{
			n = n * -1;
			len++;
		}
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
		return (len);
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		result;
	char	*min_str;
	int		len;

	min_str = "-2147483648";
	len = 0;
	result = 0;
	if (n == -2147483648)
		return (min_str);
	len = ft_nbr_char(n);
	if (len == 0)
		len = 1;
	min_str = ft_mall_str(len);
	if (n < 0)
		n = n * - 1;
	while (n > 10)
	{
		result = n % 10;
		min_str[len-- - 1] = result + 48;
		n = n / 10;
	}
	min_str[len-- - 1] = n + 48;
	if (len == 1 && min_str[1] != '\0')
		min_str[0] = '-';
	return (min_str);
}
