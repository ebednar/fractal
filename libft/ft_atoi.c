/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:47:01 by ebednar           #+#    #+#             */
/*   Updated: 2018/11/24 14:23:29 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(long long int res, long long int nb, int a)
{
	if (res < nb && a == 1)
		return (-1);
	else if (res < nb && a == -1)
		return (0);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	int				a;
	long long int	res;

	i = 0;
	nb = 0;
	a = 1;
	res = 0;
	while (str[i] == '\n' || (str[i] == '\t') || (str[i] == '\f') ||
	(str[i] == '\r') || (str[i] == '\v') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			a = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = nb * 10 + str[i++] - '0';
		if (overflow(res, nb, a) != 1)
			return (overflow(res, nb, a));
		nb = res;
	}
	return (nb * a);
}
