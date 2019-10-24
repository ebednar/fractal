/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:43:35 by ebednar           #+#    #+#             */
/*   Updated: 2018/11/29 17:51:27 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	char	*ptr1;
	char	*ptr2;
	size_t	len1;
	size_t	len2;
	size_t	i;

	ptr1 = dst;
	ptr2 = (char *)src;
	len1 = ft_strlen(ptr1);
	len2 = ft_strlen(ptr2);
	i = ft_strlen(ptr1);
	if (siz < len1 + 1)
		return (len2 + siz);
	if (siz > len1 + 1)
	{
		while (i < siz - 1 && *ptr2 != '\0')
		{
			*(ptr1 + i++) = *(ptr2);
			ptr2++;
		}
		*(ptr1 + i) = '\0';
	}
	return (len1 + len2);
}
