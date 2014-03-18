/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:25:03 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/18 18:37:58 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include "header.h"
#include <stdlib.h>
#include "libft.h"

int		ft_builtin_help(char *cmd, char **argv, char **env)
{
	if (ft_strcmp(cmd, "echo") == 0)
	{
		ft_echo(argv, env);
		return (1);
	}
	else if (ft_strcmp(cmd, "env") == 0)
	{
		ft_env(env, argv);
		return (1);
	}
	else if (ft_strcmp(cmd, "exit") == 0)
		exit(0);
	return (0);
}

int		ft_builtin(char *cmd, char **argv, char **env)
{
	if (ft_strcmp(cmd, "setenv") == 0 && argv[1])
	{
		ft_setenv(env, argv);
		return (1);
	}
	else if (ft_strcmp(cmd, "unsetenv") == 0 && argv[1])
	{
		ft_unsetenv(env, argv);
		return (1);
	}
/*	else if (ft_strcmp(cmd, "cd") == 0)
	{
		ft_cd_help(cmd, argv, env);
		return (1);
	}*/
	else if (ft_builtin_help(cmd, argv, env) == 1)
		return (1);
	return (-1);
}
/*
int		ft_exec_cmd(t_data *data) //ne pas utiliser
{
	int		ret;

	if (ft_builtin(cmd, argv, env) == 1)
		return (1);
	else
	{
		data->pid = fork();
		if (data->pid == -1)
			print_pid_error();
		if (data->pid == 0 && ft_strcmp(cmd, "cd") != 0
			&& ft_strcmp(cmd, "setenv") != 0 &&
			ft_strcmp(cmd, "unsetenv") != 0)
		{
			ft_exec(data);
			exit(0);
		}
		if (data->pid > 0)
			wait(&ret);
	}
	return (0);
}
*/
int		ft_find_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

int		ft_change_value(char *arg, char **env, int i)
{
	int		j;
	int		k;
	char	*tmp;
	char	*tmp2;

	k = 0;
	j = -1;
	tmp2 = (char *)malloc(sizeof(char) * ft_strlen(arg));
	while (env[i][++j] != '=')
		tmp2[j] = env[i][j];
	tmp2[j] = '=';
	tmp2[j + 1] = 0;
	j = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(arg));
	while (arg[k] != '=')
		k++;
	while (arg[++k] != 0)
		tmp[++j] = arg[k];
	tmp[j + 1] = 0;
	if (env[i])
		free(env[i]);
	env[i] = ft_strdup(ft_strcat(tmp2, tmp));
	free(tmp);
	free(tmp2);
	return (0);
}

int		ft_check_if_already_exist(char **env, char *arg)
{
	int		i;

	i = -1;
	while (env[++i] != 0)
	{
		if (ft_strncmp(env[i], arg, (size_t)ft_find_equal(arg)) == 0)
		{
			ft_change_value(arg, env, i);
			return (1);
		}
	}
	return (0);
}

void	ft_env_add(char **env, char **arg)
{
	int		j;
	int		i;
	char	**tmp;

	i = -1;
	j = 0;
	tmp = env;
	if (ft_check_if_already_exist(env, arg[1]) == 1)
		return ;
	while (env[j] != 0)
		j++;
	env = (char **)malloc(sizeof(char *) * (j + 3));
	while (tmp[++i] != 0)
		env[i] = ft_strdup(tmp[i]);
	env[i] = ft_strdup(arg[1]);
	env[i + 1] = 0;
}

int		ft_val_to_env(char **env, char **arg)
{
	int		i;

	i = -1;
	while (arg[1][++i] != 0)
	{
		if (arg[1][i] == '=')
		{
			ft_env_add(env, arg);
			return (1);
		}
	}
	ft_putstr("env: ");
	ft_putstr(arg[1]);
	ft_putstr(": No such file or directory\n");
	return (0);
}

int		ft_env(char **env, char **arg)
{
	if (!arg[1])
		ft_env_display(env);
	else
		ft_val_to_env(env, arg);
	return (0);
}

void	ft_env_display(char **envi)
{
	int		i;

	i = -1;
	while (envi[++i])
	{
		ft_putstr(envi[i]);
		ft_putchar('\n');
	}
}

/* int		ft_echo_arg_check(char **arg) */
/* { */
/* 	int		i; */

/* 	i = 0; */
/* 	while (arg[++i]) */
/* 	{ */
/* 		if (arg[i][0] == '$') */
/* 			return (1); */
/* 	} */
/* 	return (0); */
/* } */

int		ft_echo_value(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(line));
	while (line[i] != '=')
		i++;
	i++;
	while (line[i] != 0)
		tmp[++j] = line[i++];
	tmp[i] = 0;
	ft_putstr(tmp);
	free(tmp);
	return (0);
}

char	**ft_env_copy(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	tmp[i] = 0;
	i = -1;
	while (env[++i])
		tmp[i] = ft_strdup(env[i]);
	tmp[i] = 0;
	return (tmp);
}

void	ft_free_env(char **envi)
{
	int	i;

	i = -1;
	while (envi[++i])
		free(envi[i]);
	free(envi);
}

int		ft_echo_check_env2(char **env, char *val)
{
	int	i;
	int	j;
	char	*tmp;

	j = -1;
	i = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(val));
	while (val[++j] != 0)
		tmp[j] = ((val[j] >= 'A' || val[j] <= 'Z') ? (val[j] - 32) : val[j]);
	tmp[j] = 0;
	while (env[++i] != 0)
	{
		if (ft_strncmp(env[i], tmp, (size_t)ft_strlen(tmp)) == 0)
		{
			ft_echo_value(env[i]);
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

int		ft_echo_check_env(char **env, char *val)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (env[++i] != 0)
	{
		if (ft_strncmp(env[i], val, (size_t)ft_strlen(val)) == 0)
		{
			ft_echo_value(env[i]);
			return (1);
		}
	}
	/* if (ft_echo_check_env(data, val) == 1) */ /* Chek for uncapitalize arg */
	/* 	return (1); */
	return (-1);
}

int		ft_echo_help(char **arg, char **env)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	k = 0;
	j = -1;
	while (arg[++i])
	{
		if (arg[i][0] == '$')
		{
			tmp = (char *)malloc(sizeof(char) * ft_strlen(arg[i]));
			while (arg[i][++k] != 0)
				tmp[++j] = arg[i][k];
			if (ft_echo_check_env(env, tmp) == -1)
			{
				ft_putstr(tmp);
				ft_putstr(": Undefined variable.");
				free(tmp);
				return (-1);
			}
		}
	}
	free(tmp);
	return (0);
}

int		ft_echo(char **arg, char **env)
{
	int	i;
	int	offset;

	i = 0;
	offset = 1;
	while (arg[++i])
	{
		if (offset == 0)
			ft_putchar(' ');
		offset = 0;
		if (arg[i][0] == '$')
			ft_echo_help(arg, env);
		else
			ft_putstr(arg[i]);
	}
	ft_putchar('\n');
	return (0);
}

void	ft_checkenv_case2(char **env, char **arg, int i)
{
	char	*tmp;
	int		j;
	int		k;

	j = -1;
	k = -1;
	tmp = ft_strdup(env[i]);
	free(env[i]);
	env[i] = (char *)malloc(sizeof(char) *
	(ft_strlen(env[i] + ft_strlen(arg[2]))));
	while (tmp[++k] != '=')
		env[i][k] = tmp[k];
	env[i][k] = tmp[k];
	k++;
	while (arg[2][++j] != 0)
		env[i][k++] = arg[2][j];
	env[i][k] = 0;
	free(tmp);
}

int		ft_del_env(char **env, int i)
{
	if (!env[i + 1])
	{
		free(env[i]);
		env[i] = NULL;
		return (0);
	}
	free(env[i]);
	while (env[i] && env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
	return (0);
}

int		ft_checkenv_3(char **env, char **arg)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], arg[1], (size_t)ft_strlen(arg[1])) == 0)
		{
			ft_del_env(env, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_checkenv_2(char **env, char **arg)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], arg[1], (size_t)ft_strlen(arg[1])) == 0)
		{
			if (!arg[2])
				return (1);
			else
			{
				ft_checkenv_case2(env, arg, i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_checkenv_4(char **env, char **arg)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], arg[1], (size_t)ft_strlen(arg[1])) == 0)
			return (1);
		i++;
	}
	return (0);
}


int		ft_unsetenv(char **env, char **arg)
{
	if (ft_checkenv_4(env, arg) == 0)
		return (0);
	ft_checkenv_3(env, arg);
	return (0);
}

int		ft_check_args(char **arg)
{
	if (arg[3])
	{
		ft_putstr("setenv: Too many arguments.\n");
		return (-1);
	}
	return (0);
}

void	ft_setenv(char **env, char **arg)
{
	int		j;
	int		i;
	char	**tmp;
	char	*temp;

	i = -1;
	j = 0;
	if (ft_check_args(arg) == -1)
		return ;
	tmp = env;
	if (ft_checkenv_2(env, arg) == 1)
		return ;
	while (env[j] != 0)
		j++;
	env = (char **)malloc(sizeof(char *) * (j + 2));
	while (tmp[++i] != 0)
	{
		env[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
	}
	free(tmp);
	temp = ft_strcat(arg[1], "=");
	if (arg[2])
		temp = ft_strcat(temp, arg[2]);
	env[i] = temp;
	env[i + 1] = 0;
}

int		ft_checkenv(char **env, char *str)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strcmp(env[i], str) == 0)
			return (1);
		i++;
	}
	ft_putstr("[ENV] - Not Found.\n");
	return (0);
}
/*
void	ft_cd_help(t_data *data)
{
	if (!argv[1])
		chdir(data->home);
	else if (ft_strcmp(argv[1], "~") == 0)
		chdir(data->home);
	else if (ft_strcmp(argv[1], "-") == 0)
		chdir(data->old_pwd);
	else
		chdir(argv[1]);
	data->old_pwd = data->pwd;
}*/
