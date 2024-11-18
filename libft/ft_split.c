/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:55 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/26 11:33:41 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s);

static int	ft_word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = ft_strlen(str);
	count = 0;
	if (i == 0)
		return (0);
	i = 1;
	if (str[0] != c)
		count++;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			count ++;
		i++;
	}
	return (count);
}

static char	*ft_add(const char *str, char c, int i)
{
	char	*s;
	int		l;
	int		j;

	l = 0;
	while (str[i + l] != 0 && str[i + l] != c)
		l++;
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (0);
	j = 0;
	while (j < l)
	{
		s[j] = str[i + j];
		j++;
	}
	s[j] = 0;
	return (s);
}

/*
* Allocates (with malloc(3)) and returns an array
* of strings obtained by splitting ’s’ using the
* character ’c’ as a delimiter. The array must end
* with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;
	int		ind;

	if (!s)
		return (0);
	count = ft_word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	i = 0;
	ind = 0;
	while (s[i] && ind < count)
	{
		while (s[i] == c && s[i])
			i++;
		split[ind++] = ft_add(s, c, i);
		while (s[i] != c && s[i])
			i++;
	}
	split[ind] = 0;
	return (split);
}

int	ft_free_split(char **tab)
{
	int	i;

	if (!tab)
		return (1);
	if (!(*tab))
		return (free(tab), (1));
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

void	ft_display_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_printf("tab[%d]=%s\n", i, tab[i]);
		i++;
	}
}
