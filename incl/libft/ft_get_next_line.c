/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:56:07 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/16 18:41:23 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	do_it(int fd, char **line, char **buff)
{
	char *temp;

	temp = *line;
	*line = ft_strnjoin(temp, buff[fd], ft_strlen(buff[fd]) -
			ft_strlen(ft_strchr(buff[fd], '\n')));
	free(temp);
	temp = buff[fd];
	buff[fd] = ft_strdup(ft_strchr(buff[fd], '\n'));
	free(temp);
	if (buff[fd])
	{
		temp = buff[fd];
		buff[fd] = ft_strdup(buff[fd] + 1);
		free(temp);
		return (1);
	}
	return (0);
}

static int	zero_case(char *line)
{
	free(line);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*buff[1];
	int			ret;

	if (fd < 0 || !line || !(*line = ft_strdup("")))
		return (-1);
	ret = 1;
	while (ret != -1)
	{
		if (!buff[fd])
		{
			buff[fd] = ft_strnew(BUFF_SIZE);
			if ((ret = read(fd, buff[fd], BUFF_SIZE)) == -1)
				return (-1);
		}
		if (do_it(fd, line, buff))
			return (1);
		if (ret == 0)
		{
			if (!*line[0])
				return (zero_case(*line));
			return (1);
		}
	}
	return (-1);
}
