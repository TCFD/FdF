/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:31:41 by zbp15             #+#    #+#             */
/*   Updated: 2023/05/23 17:47:12 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_bufs(char **split_buf, char *buf)
{
	int	i;

	i = -1;
	while (split_buf[++i])
		free(split_buf[i]);
	free(split_buf);
	free(buf);
}

void	get_file_in_tab2(t_window *window, int fd)
{
	char	*buf;
	char	**split_buf;
	int		i;

	i = -1;
	buf = get_next_line(fd);
	window->size_of_line = (how_many_words(buf, ' '));
	window->points = ft_lstnew();
	window->first_link = window->points;
	window->number_of_lines = 0;
	while (buf && ++i > -1 && ++window->number_of_lines)
	{
		split_buf = ft_split(buf, ' ');
		get_line_in_tab(window, i, split_buf);
		free_bufs(split_buf, buf);
		buf = get_next_line(fd);
	}
	window->points = window->first_link;
	close(fd);
}

int	get_file_in_tab(t_window *window, char *file)
{
	int		fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (perror("Une erreur s'est produite "), 0);
	get_file_in_tab2(window, fd);
	window->number_of_points = window->number_of_lines
		* window->size_of_line;
	window->nb_of_pixels = (HEIGHT / (window->size_of_line
				+ window->number_of_lines) + WIDTH / (window->size_of_line
				+ window->number_of_lines)) / 3;
	if (!window->nb_of_pixels)
		window->nb_of_pixels = 1;
	window->x_offset = 0;
	window->y_offset = 0;
	window->z_offset = 1.5;
	window->rotation = 0.5;
	window->first_link = window->points;
	return (1);
}

void	color_stuff_up(t_window *window)
{
	if (window->points->original_z > 0)
	{
		window->points->red = 255 - (window->points->original_z / 10);
		window->points->green = 125;
		window->points->blue = 125;
	}
	else
	{
		window->points->red = 0x04 - (window->points->original_z / 10);
		window->points->green = 0x9a;
		window->points->blue = 0x8b;
	}
}

void	get_line_in_tab(t_window *win, int i, char **buf)
{
	int		j;

	j = win->size_of_line;
	while (--j > -1)
	{
		win->points->original_x = i;
		win->points->original_y = win->size_of_line - j;
		win->points->original_z = ft_atoi(ft_substr(buf[j], 0,
					ft_strchr(buf[j], ',')));
		if (ft_strrchr(buf[j], ','))
		{
			win->points->red = ft_atoi_base(ft_substr(ft_strrchr(buf[j], ','),
				3, 2), "0132456789ABCDEF", "0123456789abcdef");
			win->points->green = ft_atoi_base(ft_substr(ft_strrchr(buf[j], ','),
						5, 2), "0132456789ABCDEF", "0123456789abcdef");
			win->points->blue = ft_atoi_base(ft_substr(ft_strrchr(buf[j], ','),
						7, 2), "0132456789ABCDEF", "0123456789abcdef");
		}
		else
			color_stuff_up(win);
		ft_lstadd_back(&(win->points), ft_lstnew());
		win->points = win->points->next;
	}
}
