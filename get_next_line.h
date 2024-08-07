/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csclavon <csclavon@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:45:10 by csclavon          #+#    #+#             */
/*   Updated: 2024/08/06 16:35:17 by csclavon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE

# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>


char    *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);


#endif
