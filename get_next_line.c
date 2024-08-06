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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*verif2(int g_count, char *temp, char *end)
{
	static int	flag;

	flag = 0;
	if (g_count < 0)
	{
		free(temp);
		return (NULL);
	}
	if (g_count == 0)
	{
		if (flag == 0)
		{
			free(temp);
			return (end);
		}
		else
		{
			free(temp);
			free(end);
			return (NULL);
		}
		flag ++;
	}
	else
		return ("oui");
}

char	*get_res(char *end, char *temp)
{
	char	*res;

	if (end == NULL)
	{
		res = ft_strjoin("", temp);
		free(temp);
	}
	else
	{
		res = ft_strjoin(end, temp);
		free(temp);
		free(end);
	}
	return (res);
}

char	*get_the_end(char *end, char *res)
{
	int	count;
	int	count2;

	count = ft_strlen(res);
	count2 = 0;
	while (res[count2] != '\n' && res[count2] != '\n')
		count2 ++;
	if (res[count2] == '\n')
		count2 ++;
	if (count2 > count)
	{
		free(end);
		return (NULL);
	}
	end = malloc(sizeof(char) * (count - count2));
	if (end == NULL)
		return (NULL);
	count = count2;
	count2 = 0;
	while (res[count])
	{
		end [count2 ++] = res [count ++];
	}
	end[count2] = '\0';
	return (end);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*end;

	res = NULL;
	res = get_the_buffer(fd, end);
	if (res == NULL || *res == '\0')
	{
		free(end);
		end = NULL;
		return (NULL);
	}
	end = get_the_end(end, res);
	res = delete_tab(res);
	return (res);
}
