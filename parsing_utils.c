/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbp15 <zbp15@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:37:11 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/10 15:44:47 by zbp15            ###   ########.fr       */
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
