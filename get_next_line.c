/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:04:35 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/20 19:06:02 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_buff_length(char buff[])
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		++i;
	if (buff[i] == '\n')
		++i;
	return (i);
}
int	get_line_length(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
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

char	*create_line(char *line, char buff[])
{
	int		buff_length;
	int		line_length;
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	buff_length = get_buff_length(buff);
	line_length = get_line_length(line);
	new_line = malloc(line_length + buff_length + 1);

	while (line[i] != '\0')
		new_line[i++] = line[i];
	while (i < line_length + buff_length)
		new_line[i++] = buff[j++];
	line[i] = '\0';
	resize_buff(buff, buff_length);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (NULL);
	line = malloc(0);
	while (!has_newline(buff))
	{
		read(fd, buff, BUFFER_SIZE);
		line = create_line(line, buff);
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
