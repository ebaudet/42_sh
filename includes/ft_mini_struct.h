/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:32:55 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/26 17:40:55 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_STRUCT_H
# define FT_MINI_STRUCT_H

typedef struct			s_env
{
	struct termios		term;
	char				**env;
	struct termios		term_cpy;
}						t_env;

typedef struct			s_edit
{
	char				c;
	int					video;
	struct s_edit		*next;
	struct s_edit		*prev;
}						t_edit;

typedef struct			s_hist
{
	int					valid;
	struct s_edit		*ptr;
	struct s_hist		*next;
	struct s_hist		*prev;
}						t_hist;

typedef struct			s_help
{
	char				*key;
	int					cmp;
}						t_help;

#endif
