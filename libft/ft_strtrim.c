/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:51:18 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/01/04 13:51:01 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char				*ft_strtrim(char const *s)
{
	size_t		len;
	char		*str;

	if (s)
	{
		len = ft_strlen(s);
		while (ft_white(*((char *)s)) && s != '\0')
			s++;
		len = ft_strlen(s);
		if (len != 0)
		{
			while (ft_white(*((char *)s + len - 1)))
				len--;
		}
		str = ft_strsub(s, 0, len);
		if (str)
			return (str);
	}
	return (0);
}
