/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:10:05 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/12/01 18:50:35 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		result;
	size_t		i;

	result = 0;
	i = 0;
	while (i < n && *((unsigned char *)s1 + i)
			!= '\0' && *((unsigned char *)s2 + i) != '\0')
	{
		if (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
			i++;
		else
			break ;
	}
	result = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	return (result);
}
