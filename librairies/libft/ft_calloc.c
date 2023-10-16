/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:34:54 by rciaze            #+#    #+#             */
/*   Updated: 2023/10/04 14:17:04 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*re;

	if (nmemb == 0 || size == 0)
		return (ft_malloc(0));
	if (__SIZE_MAX__ / nmemb > size)
		re = ft_malloc(nmemb * size);
	else
		return (NULL);
	ft_bzero(re, nmemb * size);
	return (re);
}
