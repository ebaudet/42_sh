/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigleton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:03:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 17:39:05 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sigleton(int i)
{
	static int		value = 0;

	if (i == 0)
		return (value);
	else if (i == -1)
		value = 0;
	else
		value = i;
	return (value);
}
