/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:28:42 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/26 17:50:44 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	size_t		len;
	char		*str;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		while (s[i] != '\0')
		{
			str[i] = (*f)(*((char *)s + i));
			i++;
		}
		return (str);
	}
	return (0);
}
