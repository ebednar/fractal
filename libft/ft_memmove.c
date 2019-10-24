/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:22:25 by ebednar           #+#    #+#             */
/*   Updated: 2018/11/22 19:52:54 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr1 > ptr2)
		while (len-- > 0)
			*(ptr1 + len) = *(ptr2 + len);
	else if (ptr1 < ptr2)
		while (i < len)
		{
			*(ptr1 + i) = *(ptr2 + i);
			i++;
		}
	return (dst);
}
