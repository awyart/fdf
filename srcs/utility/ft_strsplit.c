/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:16:59 by awyart            #+#    #+#             */
/*   Updated: 2017/04/12 20:17:00 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	pos;
	size_t	count;

	i = 0;
	pos = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i - pos > 0)
				count++;
			pos = i + 1;
		}
		i++;
	}
	if (i - pos > 0)
		count++;
	return (count);
}

static char		*ft_create_word(char const *s, int end, int pos)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (end - pos + 1));
	while (i < end - pos)
	{
		str[i] = s[pos + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	words;
	size_t	i;
	size_t	pos;
	size_t	j;

	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	i = -1;
	pos = 0;
	j = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	while (s[++i] != '\0')
		if (s[i] == c)
		{
			if (i - pos > 0)
				str[j++] = ft_create_word(s, i, pos);
			pos = i + 1;
		}
	if (i - pos > 0)
		str[j++] = ft_create_word(s, i, pos);
	str[j] = 0;
	return (str);
}
