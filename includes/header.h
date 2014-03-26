/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:49:20 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/26 17:42:45 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*
** Struct
*/
typedef struct	s_data
{
	char		**env;
	char		*home;
	char		*old_pwd;
	char		*pwd;
}				t_data;

/*
** ft_env.c
*/
int				ft_change_value(char *arg, char **env, int i);
int				ft_check_if_already_exist(char **env, char *arg);
int				ft_env(t_data *data, char **arg);
void			ft_env_add(t_data *data, char **arg);
int				ft_val_to_env(t_data *data, char **arg);

/*
** env_tools.c
*/
int				ft_find_equal(char *str);
void			ft_env_display(char **envi);
int				ft_echo_value(char *line);
char			**ft_env_copy(char **env);
void			ft_free_env(char **envi);

/*
** ft_echo.c
*/
int				ft_echo(char **arg, char **env);
int				ft_echo_help(char **arg, char **env);
void			ft_echo_help_norm(int *i, int *k, int *j);
int				ft_echo_check_env(char **env, char *val);
int				ft_echo_check_env2(char **env, char *val);

/*
** ft_unsetenv.c
*/
int				ft_checkenv_2(char **env, char **arg);
int				ft_checkenv_3(char **env, char **arg);
int				ft_checkenv_4(char **env, char **arg);
int				ft_unsetenv(char **env, char **arg);
int				ft_del_env(char **env, int i);

/*
** ft_setenv.c
*/
void			ft_setenv(t_data *data, char **arg);
int				ft_check_args(char **arg);
int				ft_checkenv(char **env, char *str);
void			ft_checkenv_case2(char **env, char **arg, int i);

/*
** ft_builtin.c
*/
int				ft_builtin(char *cmd, char **argv, t_data *data);
int				ft_builtin_help(char *cmd, char **argv, t_data *data);
void			ft_cd_help(t_data *data, char **argv);

#endif
