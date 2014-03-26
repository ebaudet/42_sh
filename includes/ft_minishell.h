/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:14:22 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 16:00:11 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define ENTER (key[0] == 10 && key[1] == 0 && key[2] == 0 && key[3] == 0)
# define ARROW (key[0] == 27 && key[1] == 91)
# define SHIFT (key[2] == 49 && key[3] == 59)
# define ARROW_LEFT (key[2] == 68 && key[3] == 0)
# define ARROW_RIGHT (key[2] == 67 && key[3] == 0)
# define ARROW_UP (key[2] == 65 && key[3] == 0)
# define ARROW_DOWN (key[2] == 66 && key[3] == 0)
# define DELETE_R (key[2] == 51 && key[3] == 126)
# define DELETE (key[0] == 127 && key[1] == 0 && key[2] == 0 && key[3] == 0)
# define KEY_HOME (key[0] == 27 && key[1] == 91 && key[2] == 72)
# define KEY_END (key[0] == 27 && key[1] == 91 && key[2] == 70)

# define BUFF_SIZE 1024
# define FT_FILE "/.42sh_history"
# include <term.h>
# include "header.h"

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

int		ft_read(t_env **env, t_data *environ);
int		ft_filled_lste(char *key, t_edit **lst, t_hist **hst);
void	ft_print_lste(t_edit **lst);
int		ft_print_fd(char str);
int		ft_create_hst(t_hist **hst, char **env);
int		get_next_line(int fd, char **line);
void	ft_clean_thist(t_hist **hst);
int		ft_write_on_file(t_edit **lst, char **env);
void	ft_del_keyword(t_edit **lst, t_hist **hst, struct winsize ws);
void	ft_home(t_edit **lst, struct winsize ws);
void	ft_end(t_edit **lst, struct winsize ws);
int		ft_pcur(t_edit **lst);
void	ft_shift(t_edit **lst, char *key, struct winsize ws);

/*
** ft_check_key.c
*/
void	arrow_left_right(t_edit **lst, char *key, struct winsize ws);
void	arrow_up_down(t_edit **lst, t_hist **hst, char *key, struct winsize ws);
int		l_list(t_edit **lst_e);
int		position_cursor(t_edit **lst_e);
int		add_new_char(char *key, t_edit **lst, t_hist **hst, struct winsize ws);
int		ft_check_key(char *key, t_edit **lst_e, t_hist **hst);
void	ft_arrow_left_right(t_edit **lst, char *key, struct winsize ws);
void	ft_up_down(t_edit **lst, t_hist **hst, char *key, struct winsize wz);
void	get_winsize(struct winsize *ws);

/*
** ft_print_commande.c
*/
int		print_commande(t_edit **lst_e, struct winsize ws);

/*
** ft_tputs.c
*/
int		put_fd(int c);
int		ft_tputs(char *str);

/*
** ft_termios.c
*/
int		ft_termios(t_env **environ, char **env);
int		ft_envfree(char **env);

/*
** ft_env.c
*/
char	**ft_get_path(char **env);
char	*ft_getenv(char **env, char *name);

/*
** print_error.c
*/
void	ft_error(char *msg);

#endif /* !FT_MINISHELL_H */
