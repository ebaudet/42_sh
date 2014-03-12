/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:07:16 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 10:01:01 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "../includes/ft_minishell.h"

int		put_fd(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

int		ft_tputs(char *str)
{
	if (tputs(tgetstr(str, NULL), 1, put_fd) == -1)
		return (-1);
	return (0);
}
