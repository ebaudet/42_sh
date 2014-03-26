/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:21:48 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 17:10:28 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			i;
	size_t		len;
	char		*str;

	i = 0;
	len = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		while (s[i] != '\0')
		{
			str[i] = (*f)((unsigned int)i, *((char *)s + i));
			i++;
		}
		return (str);
	}
	return (0);
}
