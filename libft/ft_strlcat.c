/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:36:14 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/25 16:24:50 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		save;

	i = ft_strlen(dst);
	save = i;
	j = 0;
	k = ft_strlen(src);
	if (size < i)
		return (size + k);
	while (src[j] && i + 1 < size)
	{
		dst[i] = *((char *)src + j);
		i++;
		j++;
	}
	dst[i] = '\0';
	return (save + k);
}
