/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:04:35 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/14 23:41:24 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	size_t		bytes_read;

	line = malloc(BUFFER_SIZE + 1);
	if(!line)
		return (NULL);
	if ((bytes_read = read(fd, line, BUFFER_SIZE)) > 0)
	{
		line[bytes_read] = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}
