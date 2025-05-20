/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:04:35 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/20 18:20:56 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_length(char buff[])
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		++i;
	if (buff[i] == '\n')
		++i;
	return (i);
}

void	resize_buff(char buff[], int length)
{
	int	i = 0;

	while (buff[length] != '\0')
	{
		buff[i++] = buff[length++];
	}
	buff[i] = '\0';
	while (i < length)
	{
		buff[i++] = '\0';
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

size_t	create_line(char *line, char buff[], size_t bytes_read)
{
	int		length;
	int		i;

	i = 0;
	length = line_length(buff);
	line = malloc(bytes_read + length + 1);
	while (i < length)
	{
		line[i] = buff[i];
		++i;
	}
	resize_buff(buff, length);
	return (bytes_read + length + 1);
}

char	*get_next_line(int fd)
{
	char		*line;
	size_t		bytes_read;
	static char	buff[BUFFER_SIZE + 1];

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (NULL);
	bytes_read = 0;
	while (!has_newline(buff))
	{
		read(fd, buff, BUFFER_SIZE);
		bytes_read = create_line(line, buff, bytes_read);
		if (has_newline(line))
			break ;
	}
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
    }
	free(line);
	close(fd);
	return 0;
}
