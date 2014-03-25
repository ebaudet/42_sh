/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:49:20 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/25 19:51:24 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct 	s_data
{
	char 		**env;
}				t_data;

/*
typedef struct	s_data
{
	int			in_history;
	int			i;
	int			cursor;
	int			tmp;
	int			real_cursor;
	int			pid;
	char		buff[MAX_KEY_STRING];
	char		*name_cmd;
	char		**env;
	char		*prompt;
	char		**argv;
	char		*home;
	char		*path;
	char		*dir_cmd;
	char		*pwd;
	char		*old_pwd;
	t_list		*list;
	t_list		*charly;
	t_li		*charly2;
	t_li		*hist;
}				t_data;
*/
/*
** Prototypes
*/
/*
int		ft_get_cmd(t_data *data);
char	*ft_get_user(char **tabl, t_data *data);
int		ft_count_c(char *str, char c);
char	**ft_get_path(char **tabs);
int		ft_exec(t_data *data);
int		ft_exec_cmd(t_data *data);
char	*ft_direct_exec(t_data *data);
void	ft_get_pwd(t_data *data, char **env);
void	ft_cd_help(t_data *data);
void	print_pid_error(void);
void	ft_cmd_error(void);
void	ft_set_prompt(t_data *data);
void	ft_print_tab(char **tabl);

char	*ft_make_string(t_list *list);
*/
/*
**	Builtins
*/

int		ft_check_if_already_exist(char **env, char *arg);
int		ft_find_equal(char *str);
int		ft_change_value(char *arg, char **env, int i);
int		ft_env(t_data *data, char **arg);
void	ft_env_add(t_data *data, char **arg);
int		ft_val_to_env(t_data *data, char **arg);
char	**ft_env_copy(char **env);
void	ft_env_display(char **envi);
void	ft_free_env(char **envi);
void	ft_setenv(t_data *data, char **arg);
int		ft_check_args(char **arg);
int		ft_checkenv(char **env, char *str);
int		ft_unsetenv(char **env, char **arg);
void	ft_checkenv_case2(char **env, char **arg, int i);
int		ft_checkenv_2(char **env, char **arg);
int		ft_checkenv_3(char **env, char **arg);
int		ft_checkenv_4(char **env, char **arg);
int		ft_echo(char **arg, char **env);
int		ft_echo_help(char **arg, char **env);
int		ft_echo_check_env(char **env, char *val);
int		ft_echo_check_env2(char **env, char *val);
int		ft_echo_value(char *line);
int		ft_del_env(char **env, int i);
int		ft_builtin(char *cmd, char **argv, t_data *data);
int		ft_builtin_help(char *cmd, char **argv, t_data *data);

/*
**	termcaps
*/
/*
int		tputs_putchar(int c);
void	raw_term_mode(void);
void	default_term_mode(void);

int		is_arrow(char *buf, t_data *data);
t_list	*arrow_right(t_list *list, t_data *data);
t_list	*arrow_left(t_list *list, t_data *data);
t_li	*is_up(t_li *list, t_data *data);
t_li	*is_down(t_li *charly, t_data *data);

void	ft_while(t_data *data);
void	ft_cursor_move_offset(t_data *data);
int		is_delete(char *buf, t_data *data);
int		is_return(char *buf, t_data *data);
void	key_return(t_data *data);
*/
/*
**	List
*/
/*
void	ft_add_elem(t_list **list, char c, t_data *data);
void	ft_print_list(t_list *list, t_data *data);
t_list	*del_elem(t_list *list, t_data *data);
t_li	*add_list(t_li *list, t_data *data);
void	ft_print_history(t_li *list, t_data *data);
*/
#endif
