/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:38:36 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/08 17:21:25 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_fail(char **str, char **buffer_string)
{
	char	*temp;
	char	*temp2;
	int		i;

	free(*buffer_string);
	if (!str[0][0])
	{
		free(str[0]);
		return (NULL);
	}
	i = 0;
	while (str[0][i] != '\n' && str[0][i])
		i++;
	temp = ft_strdup(str[0]);
	temp2 = ft_substr_gnl(str[0], 0, i + 1);
	str[0] = ft_substr_gnl(temp, i + 1, ft_strlen(temp) - i);
	return (temp2);
}

char	*cut_cut_cut3(char **str, char **buffer_string, int i)
{
	char	*temp;
	char	*temp2;
	int		c;
	int		count2;

	temp = ft_strdup_gnl(buffer_string[0]);
	temp2 = ft_strdup_gnl(str[0]);
	c = i + 1;
	count2 = ft_strlen(temp) + ft_strlen(temp2);
	buffer_string[0] = ft_substr_gnl(ft_strjoin_gnl(str[0],
				buffer_string[0]), 0, c);
	str[0] = ft_substr_gnl(ft_strjoin_gnl(temp2, temp), c, count2 - c);
	return (buffer_string[0]);
}

char	*cut_cut_cut2(char **str, char **buffer_string, int i)
{
	char	*temp;
	char	*temp2;
	int		c;
	int		count2;
	int		len;

	temp = ft_strdup_gnl(buffer_string[0]);
	temp2 = ft_strdup_gnl(str[0]);
	len = ft_strlen(temp2);
	c = i + len + 1;
	count2 = ft_strlen(temp) + len;
	buffer_string[0] = ft_substr_gnl(ft_strjoin_gnl(str[0],
				buffer_string[0]), 0, c);
	str[0] = ft_substr_gnl(ft_strjoin_gnl(temp2, temp), c, count2 - c);
	return (buffer_string[0]);
}

char	*cut_cut_cut(char **str, char **buffer_string, int fd)
{
	int		i;

	i = -1;
	if (*str)
	{
		while (str[0][++i])
			if (str[0][i] == '\n')
				return (cut_cut_cut3(str, buffer_string, i));
	}
	i = -1;
	while (buffer_string[0][++i])
	{
		if (buffer_string[0][i] == '\n')
			return (cut_cut_cut2(str, buffer_string, i));
	}
	str[0] = ft_strjoin_gnl(str[0], buffer_string[0]);
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static char	*static_string;
	char		*buffer_string;
	int			boolean;

	buffer_string = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	boolean = 0;
	if (!buffer_string)
		return (NULL);
	if (!read(fd, buffer_string, BUFFER_SIZE))
		boolean = 1;
	if (boolean && static_string)
		return (read_fail(&static_string, &buffer_string));
	else if (boolean || (!buffer_string[0] && !static_string))
		return (free(buffer_string), NULL);
	return (cut_cut_cut(&static_string, &buffer_string, fd));
}
