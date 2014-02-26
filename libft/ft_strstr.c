/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:05:19 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/25 16:26:16 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		s;

	i = 0;
	j = 0;
	s = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			s = i;
			while (s2[j] == s1[i++] && s2[j] != '\0')
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

