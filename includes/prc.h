/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:24:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/25 00:23:59 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL3_H
# define FT_MINISHELL3_H
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
	int					code;
	int					nbr;
	int					prior;
	int					stat;
	char				**argv;
	struct s_op			*next;
	struct s_op			*top;
	struct s_op			*lft;
	struct s_op			*rgt;
}						t_op;

int		ft_lexer(char *str, char **env);
t_op	*ft_make_oplst(char	*str);
char	**ft_split(char *str);
int		is_space(char c);
int		is_op(char c);
char	**ft_fill_tab(char *str, int size);
t_op	*ft_create_tree(t_op **lst);
int		ft_read_tree(t_op *tree, char **env);
int		ft_execve(char *cmd, char **argv, char **env);
int		ft_opcode_tree(t_op **tmp, char **env);
char	**ft_get_path(char **tabs);
//int		ft_ar_rgt(t_op **tmp);
//int		ft_db_ar_rgt(t_op **tmp);
int		ft_ar_lft(t_op **tmp, char **env);

#endif
