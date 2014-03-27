/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:24:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/27 13:04:25 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRC_H
# define PRC_H
# define SEMICOL 0
# define AND 1
# define OR 2
# define PIPE 3
# define AR_LEFT 4
# define AR_RIGHT 5
# define DB_AR_RIGHT 6
# define COM 7
# include "header.h"

typedef struct		s_op
{
	char			*name;
	int				code;
	int				nbr;
	int				prior;
	int				stat;
	char			**argv;
	struct s_op		*next;
	struct s_op		*top;
	struct s_op		*lft;
	struct s_op		*rgt;
}					t_op;

/*
** Functions for build lexer and parser.
*/
t_op				*ft_make_oplst(char *str);
int					ft_lexer(char *str, t_data *env);
char				**ft_split(char *str);
int					is_space(char c);
int					is_op(char c);
char				**ft_get_path(char **tabs);
char				**ft_fill_tab(char *str, int size);
t_op				*ft_create_tree(t_op **lst);

/*
** Functions for read and execute the grammatical tree.
*/
int					ft_read_tree(t_op *tree, t_data *env);
int					ft_opcode_tree(t_op **tmp, t_data *env);
int					ft_execve(char *cmd, char **argv, t_data *env);

/*
** Functions that op_code, see on define.
*/
int					ft_ar_rgt(t_op **tmp, t_data *env);
int					ft_db_ar_rgt(t_op **tmp, t_data *env);
int					ft_ar_lft(t_op **tmp, t_data *env);
int					ft_and(t_op **tmp, t_data *env);
int					ft_or(t_op **tmp, t_data *env);
int					ft_semicol(t_op **tmp, t_data *env);
int					ft_pipe(t_op **tmp, t_data *env);
int					ft_check_pipes(t_op **lst);

#endif
