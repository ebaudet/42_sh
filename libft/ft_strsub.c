/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:26:54 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/12/19 15:37:14 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		rel_len;

	if (len && s)
	{
		rel_len = ft_strlen(s + start);
		if (len <= rel_len)
		{
			str = ft_strnew(len);
			if (str)
			{
				ft_strncpy(str, s + start, len);
				return (str);
			}
		}
	}
	return (0);
}
