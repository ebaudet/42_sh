/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:52:12 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 15:56:54 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_minishell.h"
#include "libft/libft.h"

static void		key_is_ok(char *key, t_edit **lst_e, t_hist **hst)
{
	struct winsize	ws;

	get_winsize(&ws);
	if (ARROW && (ARROW_LEFT || ARROW_RIGHT))
		ft_arrow_left_right(lst_e, key, ws);
	else if (ARROW && (ARROW_UP || ARROW_DOWN))
		ft_up_down(lst_e, hst, key, ws);
	else if (ARROW && DELETE_R)
	{
		ft_filled_lste("~", lst_e, hst);
		ft_tputs("rc");
		ft_tputs("cd");
		ft_print_lste(lst_e);
	}
	else if (DELETE)
		ft_del_keyword(lst_e, hst, ws);
	else if (ft_isprint(*key))
		add_new_char(key, lst_e, hst, ws);
	else if (KEY_HOME)
		ft_home(lst_e, ws);
	else if (KEY_END)
		ft_end(lst_e, ws);
	else if (ARROW && SHIFT && key[4] == 50 && (key[5] == 68 || key[5] == 67))
		ft_shift(lst_e, key, ws);
}

int				ft_check_key(char *key, t_edit **lst_e, t_hist **hst)
{
	if (key)
		key_is_ok(key, lst_e, hst);
	else
		return (-1);
	return (0);
}
