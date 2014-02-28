/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:29:11 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 10:00:50 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <term.h>
#include <stdlib.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

static int		cpy_term(t_env **environ)
{
	int			fd;

	fd = 0;
	fd = open(ttyname(0), O_RDWR);
	if (fd == -1)
		return (-1);
	if (tcgetattr(fd, &(*environ)->term) == -1
			|| tcgetattr(fd, &(*environ)->term_cpy) == -1)
		return (-1);
	(*environ)->term.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(fd, TCSANOW, &(*environ)->term) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int				ft_termios(t_env **environ)
{
	char		bp[2048];
	char		*term;

	term = NULL;
	*environ = (t_env *)malloc(sizeof(t_env));
	if (!*environ)
		return (-1);
	if (cpy_term(environ) < 0)
		return (-1);
	if (!(term = getenv("TERM")))
		return (-1);
	if (!(tgetent(bp, term)))
		return (-1);
	return (0);
}