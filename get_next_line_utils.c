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

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		s1_len;
	int		s2_len;

	s1_len = -1;
	s2_len = -1;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char)
			* (ft_strlen(s2) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1 != NULL && s1[++s2_len] != '\0')
		s3[++s1_len] = s1[s2_len];
	s2_len = -1;
	while (s2 != NULL && s2[++s2_len] != '\0')
		s3[++s1_len] = s2[s2_len];
	s3[++s1_len] = '\0';
	return (s3);
}

char	*delete_tab(char *res)
{
	int	count;

	count = 0;
	while (res[count] != '\n')
	{
		if (res[count == '\0'])
			return (res);
		count ++;
	}
	res[count + 1] = '\0';
	return (res);
}

char	*get_the_buffer2(int fd, char *temp, char *res, int g_count)
{
	char	*temp2;

	while (verif(res) == 0)
	{
		temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (temp == NULL)
			return (NULL);
		g_count = read(fd, temp, BUFFER_SIZE);
		temp[g_count] = '\0';
		if (g_count == 0)
		{
			free(temp);
			break ;
		}
		temp2 = ft_strjoin("", res);
		free(res);
		res = ft_strjoin(temp2, temp);
		free(temp);
		free(temp2);
	}
	return (res);
}

char	*get_the_buffer(int fd, char *end)
{
	char	*temp;
	char	*res;
	int		g_count;
	char	*si;

	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	g_count = read(fd, temp, BUFFER_SIZE);
	si = verif2(g_count, temp, end);
	if (si == end)
		return (end);
	else
	{
		temp[g_count] = '\0';
		res = get_res(end, temp);
		res = get_the_buffer2(fd, temp, res, g_count);
		return (res);
	}
}

int	verif(char *res)
{
	int	count;

	count = 0;
	while (res[count])
	{
		if (res[count] == '\n')
			return (1);
		count ++;
	}
	return (0);
}
