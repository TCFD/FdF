/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:12:21 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/20 15:57:29 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_points(t_window *win, t_list *point_a, t_list *point_b,
	t_point *point)
{
	point->x1 = ((point_a->original_x + win->x_offset) * win->nb_of_pixels
			- point_a->original_y * win->nb_of_pixels) * 0.82 + (WIDTH / 2);
	point->y1 = (((point_a->original_x * win->nb_of_pixels
					+ (point_a->original_y + win->y_offset) * win->nb_of_pixels)
				* win->rotation) + (point_a->original_z * win->z_offset
				* -win->nb_of_pixels)) * 0.82 + (HEIGHT / 2);
	point->x2 = ((point_b->original_x + win->x_offset) * win->nb_of_pixels
			- point_b->original_y * win->nb_of_pixels) * 0.82 + (WIDTH / 2);
	point->y2 = (((point_b->original_x * win->nb_of_pixels
					+ (point_b->original_y + win->y_offset) * win->nb_of_pixels)
				* win->rotation) + (point_b->original_z
				* win->z_offset * -win->nb_of_pixels)) * 0.82 + (HEIGHT / 2);
	return (calculate_the_rest(point));
}

int	calculate_the_rest(t_point *point)
{
	if (point->x1 < 0 || point->x1 > WIDTH || point->y1 < 0 || point->y1
		> HEIGHT || point->x2 < 0 || point->x2 > WIDTH || point->y2
		< 0 || point->y2 > HEIGHT)
		return (0);
	point->ex = abs(point->x2 - point->x1);
	point->ey = abs(point->y2 - point->y1);
	point->static_ex = point->ex;
	point->static_ey = point->ey;
	point->delta_y = 2 * point->ey;
	point->delta_x = 2 * point->ex;
	if (point->x1 > point->x2)
		point->x_incr = -1;
	else
		point->x_incr = 1;
	if (point->y1 > point->y2)
		point->y_incr = -1;
	else
		point->y_incr = 1;
	return (1);
}

int	create_window(t_window *window)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
		return (0);
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "Fdf");
	if (window->win_ptr == NULL)
		return (perror("Une erreur s'est produite "), mlx_destroy_display
			(window->mlx_ptr), free(window->mlx_ptr), 0);
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	if (window->img_ptr == NULL)
		return (perror("Une erreur s'est produite "), mlx_destroy_window
			(window->mlx_ptr, window->win_ptr), mlx_destroy_display
			(window->mlx_ptr), free(window->mlx_ptr), 0);
	window->img_data = (mlx_get_data_addr(window->img_ptr, &(window->bits),
				&(window->size_line_img), &(window->endian)));
	if (window->img_data == NULL)
		return (perror("Une erreur s'est produite "), mlx_destroy_image
			(window->mlx_ptr, window->img_ptr), mlx_destroy_window
			(window->mlx_ptr, window->win_ptr), mlx_destroy_display
			(window->mlx_ptr), free(window->mlx_ptr), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (ft_putstr("Bad usage. Please do : ./fdf \"map\""));
	if (!create_window(&window))
		return (0);
	if (!get_file_in_tab(&window, argv[argc - 1]))
		return (mlx_destroy_image(window.mlx_ptr, window.img_ptr),
			mlx_destroy_window(window.mlx_ptr, window.win_ptr),
			mlx_destroy_display(window.mlx_ptr), free(window.mlx_ptr), 0);
	print_to_image(&window, -1, -1, window.points);
	mlx_loop_hook(window.mlx_ptr, &handle_no_event, &window);
	mlx_hook(window.win_ptr, 2, KeyPressMask, &key_press, &window);
	mlx_hook(window.win_ptr, 17, KeyPressMask, &destroy_window, &window);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_image(window.mlx_ptr, window.img_ptr);
	mlx_destroy_display(window.mlx_ptr);
	ft_lstclear(&(window.first_link));
	return (free(window.mlx_ptr), 1);
}
