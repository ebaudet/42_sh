/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:26:38 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/12/01 19:51:32 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (s1)
	{
		s2 = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + 1)));
		if (s2 != NULL)
			ft_strcpy(s2, s1);
		return (s2);
	}
	return (0);
}
