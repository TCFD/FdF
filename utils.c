/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:37:11 by rciaze            #+#    #+#             */
/*   Updated: 2023/04/09 15:08:17 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *window)
{
	(void)(window);
	return (0);
}

int	destroy_window(t_window *window)
{
	return (mlx_destroy_window(window->mlx_ptr, window->win_ptr));
}

int	key_press(int keycode, t_window *window)
{
	if (keycode == 65307)
		return (mlx_destroy_window(window->mlx_ptr, window->win_ptr));
	if (keycode == 'q')
		window->nb_of_pixels += 1;
	if (keycode == 'e')
		if (window->nb_of_pixels > 1)
			window->nb_of_pixels -= 1;
	if (keycode == 's')
		window->y_offset -= 5;
	if (keycode == 'w')
		window->y_offset += 5;
	if (keycode == 'a')
		window->x_offset += 5;
	if (keycode == 'd')
		window->x_offset -= 5;
	if (keycode == 'r')
		window->z_offset += window->z_offset / 10;
	if (keycode == 'f')
		window->z_offset -= window->z_offset / 10;
	window->points = window->first_link;
	mlx_destroy_image(window->mlx_ptr, window->img_ptr);
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	window->img_data = (mlx_get_data_addr(window->img_ptr, &(window->bits),
				&(window->size_line_img), &(window->endian)));
	return (print_to_image(window, -1, -1, window->points), 0);
}
