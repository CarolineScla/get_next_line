/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csclavon <csclavon@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:45:10 by csclavon          #+#    #+#             */
/*   Updated: 2024/08/06 16:35:21 by csclavon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*d;

	d = malloc(ft_strlen(s) + 1);
	if (d == 0)
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (len > 0 && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
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

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}