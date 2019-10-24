/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:05:59 by ebednar           #+#    #+#             */
/*   Updated: 2019/01/15 16:31:09 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	char	*str;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while ((*ptr == ' ' || *ptr == '\n' || *ptr == '\t') && len > 0)
	{
		ptr++;
		len--;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		str[i] = *ptr;
		ptr++;
	}
	return (str);
}
