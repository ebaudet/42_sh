/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:34:08 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 15:36:09 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_minishell.h"

int		add_new_char(char *key, t_edit **lst, t_hist **hst, struct winsize ws)
{
	ft_filled_lste(key, lst, hst);
	print_commande(lst, ws);
	return (0);
}

