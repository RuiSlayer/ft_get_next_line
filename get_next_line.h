/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slayer <slayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:05:10 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/28 19:50:33 by slayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
int		get_buff_length(char *buff);
int		get_line_length(char *line);
size_t	resize_buff(char *buff);
int		has_newline(char *line);
char	*create_line(char *line, char *buff);

#endif