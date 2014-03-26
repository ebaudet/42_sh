/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:38:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 16:59:58 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = ft_strnew(len_s1 + len_s2);
		if (str)
		{
			str = ft_strcpy(str, s1);
			str = ft_strncat(str, s2, len_s2);
			return (str);
		}
	}
	return (0);
}
