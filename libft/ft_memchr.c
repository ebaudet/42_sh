/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:05:24 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/26 15:12:04 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (*((unsigned char *)s + i) == (unsigned char)c)
				return ((void *)s + i);
			i++;
		}
	}
	return (0);
}
