/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:14:22 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/07 19:51:48 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# define ARROW key[0] == 27 && key[1] == 91
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

int			ft_read(t_env **env);
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

#endif /* !FT_MINISHELL_H */
