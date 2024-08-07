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

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

static char *get_line(char **remainder)
{
    char *newline_pos;
    char *line;
    char *temp;

    newline_pos = ft_strchr(*remainder, '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        line = ft_strdup(*remainder);
        temp = ft_strdup(newline_pos + 1);
        free(*remainder);
        *remainder = temp;
    }
    else
    {
        line = ft_strdup(*remainder);
        free(*remainder);
        *remainder = NULL;
    }
    return (line);
}

static int read_to_remainder(int fd, char **remainder)
{
    char buffer[BUFFER_SIZE + 1];
    char *temp;
    int bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        if (*remainder)
        {
            temp = ft_strjoin(*remainder, buffer);
            free(*remainder);
            *remainder = temp;
        }
        else
        {
            *remainder = ft_strdup(buffer);
        }
        if (ft_strchr(buffer, '\n'))
            break;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    return (bytes_read);
}

char *get_next_line(int fd)
{
    static char *remainder;
    int bytes_read;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = read_to_remainder(fd, &remainder);
    if (bytes_read < 0)
        return (NULL);
    if (bytes_read == 0 && (!remainder || *remainder == '\0'))
        return (NULL);
    line = get_line(&remainder);
    return (line);
}