/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbp15 <zbp15@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:18:32 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/10 15:55:36 by zbp15            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*d_list;
	int		i;

	if (lst == NULL)
		return ;
	i = ft_lstsize(*lst);
	d_list = *(lst);
	while (i-- > 0)
	{
		temp = d_list->next;
		free(d_list);
		d_list = temp;
	}
	*lst = NULL;
}
