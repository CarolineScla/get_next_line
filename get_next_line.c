/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csclavon <csclavon@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:45:10 by csclavon          #+#    #+#             */
/*   Updated: 2024/08/06 14:27:28 by csclavon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*extract_line(char **leftover);

char	*get_next_line(int fd)
{
	static char *leftover = NULL;
	char buffer[1];
	ssize_t bytes_read;
	char *newline_pos;

	if (fd < 0)
		return (NULL);

	while ((bytes_read = read(fd, buffer, 1)) > 0) {
		buffer[bytes_read] = '\0';
		char *temp = ft_strjoin(leftover ? leftover : "", buffer);
		free(leftover);
		leftover = temp;
		newline_pos = ft_strchr(leftover, '\n');
		if (newline_pos)
			break;
	}

	if (bytes_read < 0 || (bytes_read == 0 && (!leftover || !*leftover)))
		return (NULL);

	char *line = extract_line(&leftover);
	return (line);
}

char	*extract_line(char **leftover)
{
	char *line;
	char *newline_pos;

	newline_pos = ft_strchr(*leftover, '\n');
	if (newline_pos) {
		line = ft_substr(*leftover, 0, newline_pos - *leftover + 1);
		char *new_leftover = ft_strdup(newline_pos + 1);
		free(*leftover);
		*leftover = new_leftover;
	} else {
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}
