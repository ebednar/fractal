/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:33:11 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/04 16:07:12 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	w_len(char const *s, int i, char c)
{
	size_t len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i + 1] != '\0')
		{
			if (s[i + 1] != c)
				count++;
			i++;
		}
		i++;
	}
	return (count);
}

static char	**sclear(char **ptr, int j)
{
	int i;

	i = 0;
	while (i <= j)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	len;
	int		i;
	int		j;
	char	**ptr;

	i = 0;
	j = 0;
	if (!s || !(ptr = (char **)malloc(sizeof(char *) * (words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (i == 0 || (s[i] == c && s[i + 1] != '\0'))
			if ((i == 0 && s[i] != c) || s[i + 1] != c)
			{
				if (s[i] == c)
					i++;
				len = w_len(s, i, c);
				if (!(ptr[j] = (char *)malloc(sizeof(char*) * (len + 1))))
					return (sclear(ptr, j));
				ptr[j++] = ft_strsub(s, i, len);
			}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
