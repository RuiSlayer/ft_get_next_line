/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:05:10 by ruislayer         #+#    #+#             */
/*   Updated: 2025/05/26 21:10:10 by ruislayer        ###   ########.fr       */
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

# define BUFFER_SIZE 10000000

char	*get_next_line(int fd);
int		get_buff_length(char buff[]);
int		get_line_length(char *line);
size_t	resize_buff(char buff[]);
int		has_newline(char *buff);
char	*create_line(char *line, char buff[]);

#endif