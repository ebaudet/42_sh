/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:12:10 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/25 16:25:44 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		s;

	i = 0;
	j = 0;
	s = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s2[j] == s1[i])
		{
			s = i;
			while (s2[j] == s1[i] && s2[j] != '\0' && i++ < n)
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + s);
			i = s;
		}
		i++;
		j = 0;
	}
	return (0);
}
