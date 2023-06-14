/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:34:59 by zbp15             #+#    #+#             */
/*   Updated: 2023/05/23 17:41:19 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	case_1(t_window *window, t_point *point, t_color *color)
{
	int	i;

	i = -1;
	while (++i <= point->static_ex)
	{
		window->img_data[(point->y1 * window->size_line_img) + (point->x1
				* 4) + 2] = (color->red);
		window->img_data[(point->y1 * window->size_line_img) + (point->x1
				* 4) + 1] = (color->green);
		window->img_data[(point->y1 * window->size_line_img) + (point->x1
				* 4)] = color->blue;
		point->x1 += point->x_incr;
		point->ex -= point->delta_y;
		if (point->ex < 0)
		{
			point->y1 += point->y_incr;
			point->ex += point->delta_x;
		}
		color->red += color->red_offset;
		color->green += color->green_offset;
		color->blue += color->blue_offset;
	}
}

void	case_2(t_window *window, t_point *point, t_color *color)
{
	int	i;

	i = -1;
	while (++i <= point->static_ey)
	{
		window->img_data[(point->y1 * window->size_line_img) + (point->x1
				* 4) + 2] = (color->red);
		window->img_data[(point->y1 * window->size_line_img) + (point->x1
				* 4) + 1] = (color->green);
		window->img_data[(point->y1 * window->size_line_img) + (point->x1
				* 4)] = color->blue;
		point->y1 += point->y_incr;
		point->ey -= point->delta_x;
		if (point->ey < 0)
		{
			point->x1 += point->x_incr;
			point->ey += point->delta_y;
		}
		if (color->red + color->red_offset)
			color->red += color->red_offset;
		if (color->green + color->green_offset)
			color->green += color->green_offset;
		if (color->blue + color->blue_offset)
			color->blue += color->blue_offset;
	}
}

int	clic(t_window *window, t_list *pointa, t_list *pointb, t_color *color)
{
	t_point	point;

	if (!calculate_points(window, pointa, pointb, &point))
		return (0);
	color->red_offset = (pointb->red - color->red) / (int)(sqrt
			(pow(point.x2 - point.x1, 2) + pow(point.y2 - point.y1, 2)) + 1);
	color->green_offset = (pointb->green - color->green) / (int)(sqrt
			(pow(point.x2 - point.x1, 2) + pow(point.y2 - point.y1, 2)) + 1);
	color->blue_offset = (pointb->blue - color->blue) / (int)(sqrt
			(pow(point.x2 - point.x1, 2) + pow(point.y2 - point.y1, 2)) + 1);
	if (point.static_ex > point.static_ey)
		case_1(window, &point, color);
	if (point.static_ex <= point.static_ey)
		case_2(window, &point, color);
	return (0);
}

void	print_to_image(t_window *win, int k, int i, t_list *temp)
{
	t_color		color;

	while (++i < win->size_of_line)
		temp = temp->next;
	while (++k < win->number_of_points - 1)
	{
		color.red = win->points->red;
		color.green = win->points->green;
		color.blue = win->points->blue;
		if ((k + 1) % win->size_of_line && win->points->original_x < WIDTH
			&& win->points->original_y < HEIGHT)
			clic(win, win->points, win->points->next, &color);
		if (k + win->size_of_line < win->number_of_points
			&& win->points->original_x < WIDTH
			&& win->points->original_y < HEIGHT)
		{
			color.red = win->points->red;
			color.green = win->points->green;
			color.blue = win->points->blue;
			clic(win, win->points, temp, &color);
			temp = temp->next;
		}
		win->points = win->points->next;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
