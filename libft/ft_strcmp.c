/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:25:22 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 17:00:27 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int			result;
	int			i;

	result = 0;
	i = 0;
	while (*((unsigned char *)s1 + i)
			!= '\0' && *((unsigned char *)s2 + i) != '\0')
	{
		if (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
			i++;
		else
			break ;
	}
	return (result = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
