/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slayer <slayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:04:35 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/31 23:52:33 by slayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	bytes_read = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buff[0] == '\0')
			bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free(line), NULL);
		line = create_line(line, buff);
		if (!line)
			return (NULL);
		resize_buff(buff);
		if (has_newline(line))
			return (line);
	}
	return (line);
}

/* int main()
{
	int fd = open("big_line_no_nl", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
} */