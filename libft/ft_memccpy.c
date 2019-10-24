/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:48:05 by ebednar           #+#    #+#             */
/*   Updated: 2018/11/22 20:08:26 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;
	unsigned char s;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	s = (unsigned char)c;
	while (n > 0)
	{
		*ptr1 = *ptr2;
		if (*ptr2 == s)
			return ((unsigned char *)(ptr1 + 1));
		ptr1++;
		ptr2++;
		n--;
	}
	return (NULL);
}
