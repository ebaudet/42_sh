/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:05:29 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/26 18:40:10 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if ((!s1 && !s2) || !n)
		return (1);
	if (s1 && s2)
	{
		i = ft_strncmp(s1, s2, (n - 1));
		if (i == 0)
			return (1);
	}
	return (0);
}
