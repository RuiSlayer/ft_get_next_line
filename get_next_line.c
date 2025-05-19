/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:04:35 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/19 20:16:44 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_lenth(char buff[])
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		++i;
	if (buff[i] == '\n')
		++i;
	return (i);
}

void	resize_buff(char buff[], int lenth)
{
	int		i;

	i = 0;
	while (buff[lenth])
	{
		buff[i] = buff[lenth];
		++i;
		++lenth;
	}
	while (buff[lenth])
	{
		buff[i] = '\0';
	}
}

int	has_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*create_line(char buff[])
{
	char	*line;
	int		length;
	int		i;

	i = 0;
	length = line_lenth(buff);
	line = malloc(length + 1);
	if (!line)
		return (NULL);
	while (i < length)
	{
		line[i] = buff[i];
		++i;
	}
	line[i] = '\0';
	resize_buff(buff, length);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	size_t		bytes_read;
	static char	buff[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (!has_newline(buff) && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (buff[0] == '\0')
		return (NULL);
	line = create_line(buff);
	return (line);
}

#include <fcntl.h>      // for open()
#include <unistd.h>     // for close()
#include <stdio.h>      // for printf()
#include <stdlib.h>     // for free()

int main()
{
	int     fd;
    char    *line;
	fd = open("test", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
	close(fd);
	return 0;
}
