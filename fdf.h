/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:39:16 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/28 09:27:35 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FALSE 0
# define TRUE 1
# define WIDTH 1920
# define HEIGHT 1050
# include "librairies/minilibx-linux/mlx.h"
# include "librairies/libft/libft.h"
# include <X11/X.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

typedef struct s_points
{
	int		delta_x;
	int		delta_y;
	int		ex;
	int		ey;
	int		x_incr;
	int		y_incr;
	int		static_ex;
	int		static_ey;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}	t_point;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits;
	int		size_line_img;
	int		endian;
	t_list	*points;
	t_list	*first_link;
	int		size_of_line;
	int		number_of_lines;
	int		number_of_points;
	float	nb_of_pixels;
	float	y_offset;
	float	x_offset;
	float	z_offset;
	float	rotation;
}	t_window;

typedef struct s_color
{
	float		red_offset;
	float		green_offset;
	float		blue_offset;
	float		red;
	float		green;
	float		blue;
}	t_color;

int		get_file_in_tab(t_window *window, char *file);
void	get_line_in_tab(t_window *win, int i, char **buf);
void	free_bufs(char **split_buf, char *buf);
int		calculate_points(t_window *win, t_list *pa, t_list *pb, t_point *point);
void	print_to_image(t_window *window, int k, int i, t_list *temp);
void	free_all_stuff(t_list *list);
int		handle_no_event(void *window);
int		key_press(int keycode, t_window *window);
int		calculate_the_rest(t_point *point);
int		destroy_window(t_window *window);

#endif