/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:54:11 by ymohl-cl          #+#    #+#             */
/*   Updated: 2013/12/18 21:33:41 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**ft_count_word(char const *s, char c)
{
	int		i;
	int		nbr;
	char	**tab;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		nbr++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab = (char **)malloc(sizeof(char *) * (nbr + 1));
	tab[nbr] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		save;
	int		i;
	int		j;
	int		len;
	char	**tab;

	save = 0;
	i = 0;
	j = 0;
	if (s && c)
	{
		tab = ft_count_word(s, c);
		while (s[i] != '\0')
		{
			len = 0;
			while (s[i] == c && s[i] != '\0')
				i++;
			save = i;
			while (s[i] != c && s[i] != '\0' && len++ >= 0)
				i++;
			tab[j++] = ft_strsub(s, save, len);
		}
		return (tab);
	}
	return (0);
}
