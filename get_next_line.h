/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:23:59 by prossi            #+#    #+#             */
/*   Updated: 2021/10/19 12:03:44 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_the_buffer(int fd, char *end);
char	*get_the_end(char *end, char *res);
char	*get_the_buffer2(int fd, char *temp, char *res,
			int g_count);
char	*delete_tab(char *res);
size_t	ft_strlen(const char *s);
int		verif(char *res);
char	*verif2(int g_count, char *temp, char *end);
char	*get_res(char *end, char*temp);
char	*ft_strjoin(char const *s1, char const *s2);

#endif