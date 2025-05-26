/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:04:35 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/26 21:10:42 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	static int	resto;
	char		*line;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buff + resto, BUFFER_SIZE);
		if (bytes_read == 0 && !buff[0])
			return (NULL);
		line = create_line(line, buff);
		resto = resize_buff(buff);
		if (has_newline(line))
			break ;
	}
	return (line);
}

/* #include <fcntl.h>      // for open()
#include <unistd.h>     // for close()
#include <stdio.h>      // for printf()
#include <stdlib.h>     // for free()

int main()
{
	int     fd;
    char    *line;
	fd = open("test.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
    }
	free(line);
	close(fd);
	return 0;
} */