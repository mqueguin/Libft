/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:30:13 by mqueguin          #+#    #+#             */
/*   Updated: 2020/09/24 15:27:08 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_blank(char pos, char c)
{
	if (pos == c)
		return (1);
	return (0);
}

int		ft_count_words(const char *s, char c)
{
	int		i;
	int		j;
	int		is_word;

	i = 0;
	j = 0;
	is_word = 0;
	while (s[i])
	{
		if (ft_is_blank(s[i], c))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			j++;
		}
		i++;
	}
	return (j);
}

int		ft_count_letters(const char *s, int i, char c)
{
	int		index;

	index = 0;
	while (!ft_is_blank(s[i++], c))
		index++;
	return (index);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		nb_args;
	int		i_in_words;

	tab = NULL;
	i = 0;
	nb_args = 0;
	i_in_words = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (!ft_is_blank(s[i], c))
		{
			if (i_in_words == 0)
				if (!(tab[nb_args] = (char*)malloc(sizeof(char) * ft_count_letters(s, i, c) + 1)))
					return (NULL);
			tab[nb_args][i_in_words] = s[i];
			tab[nb_args][i_in_words + 1] = '\0';
			i_in_words++;
		}
		if (ft_is_blank(s[i], c) && !ft_is_blank(s[i + 1], c) && i_in_words > 0)
		{
			nb_args++;
			i_in_words = 0;
		}
		i++;
	}
	if (nb_args == 0)
		tab[1] = NULL;
	else
		tab[nb_args] = NULL; 
	return (tab);
}
