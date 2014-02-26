/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 09:49:54 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/11/30 09:53:05 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *c, int fd)
{
	int		i;

	i = 0;
	while (c[i] != '\0')
		ft_putchar_fd(c[i++], fd);
	ft_putchar_fd('\n', fd);
}
