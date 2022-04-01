/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:26:52 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/03 18:16:20 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int					next_line(char **backup, char **line)
{
	char			*temp;
	int				i;

	i = 0;
	while ((*backup)[i])
	{
		if ((*backup)[i] == '\n')
		{
			(*backup)[i] = '\0';
			*line = ft_strdup(*backup);
			temp = ft_strdup(*backup + i + 1);
			free(*backup);
			*backup = temp;
			return (1);
		}
		i++;
	}
	return (1);
}

int					last_line(char **backup, char **line, int res)
{
	if (res < 0)
		return (-1);
	if (*backup && (ft_strchr(*backup, '\n') != NULL))
		return (next_line(backup, line));
	else if (*backup)
	{
		*line = *backup;
		*backup = NULL;
		return (0);
	}
	else
		*line = ft_strdup("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (ft_strchr(backup[fd], '\n') != NULL)
			return (next_line(&backup[fd], line));
	}
	return (last_line(&backup[fd], line, res));
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int ret;
	int fd;
	char *line;
	int i;

	i  = 0;
	fd = open("hello.txt",O_RDONLY);
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		printf("%d :%s \n", i, line);
		free(line);
		i++;
	}
	printf("%d :%s \n", i, line);
	free(line);
	return (0);
}