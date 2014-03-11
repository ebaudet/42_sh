/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:14:22 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/11 14:52:58 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# define ARROW key[0] == 27 && key[1] == 91
# define SHIFT key[2] == 49 && key[3] == 59
# define BUF_SIZE 1024
# define FT_FILE ".history.txt"
# include <term.h>

typedef struct			s_env
{
	struct termios		term;
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

int			ft_read(t_env **env, char **environ);
int			ft_check_key(char *key, t_edit **lst_e, t_hist **hst);
int			ft_tputs(char *str);
int			ft_termios(t_env **environ);
int			ft_filled_lste(char *key, t_edit **lst, t_hist **hst);
void		ft_print_lste(t_edit **lst);
int			ft_print_fd(char str);
int			ft_create_hst(t_hist **hst);
int			get_next_line(int fd, char **line);
void		ft_clean_thist(t_hist **hst);
int			ft_write_on_file(t_edit **lst);
void		ft_del_keyword(t_edit **lst, t_hist **hst);
void		ft_home(t_edit **lst);
void		arrow_left_right(t_edit **lst, char *key);
void		ft_end(t_edit **lst);
int			ft_poscurseur(t_edit **lst);
void		ft_shift(t_edit **lst, char *key);

#endif /* !FT_MINISHELL_H */
