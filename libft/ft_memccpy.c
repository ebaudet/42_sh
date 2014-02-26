/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:52:34 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/25 16:22:26 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		*((char *) s1 + i) = *((char *) s2 + i);
		if (*((char *)s1 + i) == (unsigned char)c)
				return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
