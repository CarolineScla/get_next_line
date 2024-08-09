/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csclavon <csclavon@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:45:10 by csclavon          #+#    #+#             */
/*   Updated: 2024/08/09 18:08:25 by csclavon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **leftover);
char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		buffer[1];
	ssize_t		bytes_read;
	char		*newline_pos;
	char		*new_leftover;
	char		*line;

	if (fd < 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (leftover != NULL)
		{
			new_leftover = ft_strjoin(leftover, buffer);
			free(leftover);
			leftover = new_leftover;
		}
		else
			leftover = ft_strjoin("", buffer);
		newline_pos = ft_strchr(leftover, '\n');
		if (newline_pos)
			break ;
	}
	if (bytes_read < 0 || (bytes_read == 0 && (!leftover || !*leftover)))
		return (NULL);
	*line = extract_line(&leftover);
	return (line);
}

char	*extract_line(char **leftover)
{
	char	*line;
	char	*newline_pos;
	char	*new_leftover;

	newline_pos = ft_strchr(*leftover, '\n');
	if (newline_pos)
	{
		line = ft_substr(*leftover, 0, newline_pos - *leftover + 1);
		new_leftover = ft_strdup(newline_pos + 1);
		free(*leftover);
		*leftover = new_leftover;
	}
	else
	{
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	while (s2[k] != '\0')
		str[i++] = s2[k++];
	str[i] = '\0';
	return (str);
}
