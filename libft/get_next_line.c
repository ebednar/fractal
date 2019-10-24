/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:29:21 by ebednar           #+#    #+#             */
/*   Updated: 2019/02/06 17:15:03 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char **tmp, int *ret)
{
	char	*str;
	char	*arr;
	int		i;

	i = 0;
	if (**tmp == '\0' || *tmp == NULL)
	{
		*ret = 0;
		return (NULL);
	}
	while ((*tmp)[i] != '\n' && (*tmp)[i] != '\0')
		i++;
	if ((*tmp)[i] == '\n')
	{
		(*tmp)[i] = '\0';
		i++;
	}
	str = ft_strdup(*tmp);
	arr = ft_strdup(*tmp + i);
	free(*tmp);
	*tmp = arr;
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			nbread;
	static char	*tmp[1];
	char		*arr;
	int			ret;

	if (BUFF_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	ret = 1;
	if (!(tmp[fd]))
		tmp[fd] = ft_strnew(0);
	while ((nbread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		arr = ft_strjoin(tmp[fd], buff);
		free(tmp[fd]);
		tmp[fd] = arr;
		if (ft_strchr(tmp[fd], '\n') != NULL)
			break ;
	}
	if (nbread < 0 || (nbread == 0 && tmp[fd] == NULL))
		return (-1);
	*line = get_line(&tmp[fd], &ret);
	return (ret);
}
