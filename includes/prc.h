/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:24:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/12 14:19:03 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL3_H
# define FT_MINISHELL3_H

/*ft_lexer.c*/

# define SEMICOL 0
# define AND 1
# define OR 2
# define PIPE 3
# define AR_LEFT 4
# define AR_RIGHT 5
# define DB_AR_RIGHT 6
# define COM 7

typedef struct			s_op
{
	char				*name;
	char				**argv;
	int					code;
	int					prior;
	struct s_op			*next;
	struct s_op			*prev;
	struct s_op			*parent;
	struct s_op			*right;
	struct s_op			*left;
}						t_op;

int		ft_lexer(char *str, char **env);
t_op	*ft_make_oplst(char	*str);
char	**ft_split(char *str);
int		is_space(char c);
int		is_op(char c);
char	**ft_fill_tab(char *str, int size);
#endif
