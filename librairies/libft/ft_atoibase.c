/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbp15 <zbp15@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:35:54 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/10 14:48:13 by zbp15            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlen2(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (i == 1)
		return (0);
	return (i);
}

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	is_base_valid(char *base, int i)
{
	int		compteur;
	int		compteur2;
	int		where_am_i;
	char	*is_already_here;

	is_already_here = ft_calloc(sizeof(char), 600);
	while (is_already_here[++i])
		is_already_here[i] = 0;
	compteur = -1;
	compteur2 = 0;
	where_am_i = 0;
	while (base[++compteur])
	{
		while (is_already_here[compteur2])
		{
			if (base[compteur] == is_already_here[compteur2]
				|| base[compteur] == '+' || base[compteur] == '-')
				return (free(is_already_here), 0);
			compteur2++;
		}
		is_already_here[where_am_i] = base[compteur];
		compteur2 = 0;
		where_am_i++;
	}
	return (free(is_already_here), 1);
}

int	ft_atoi_base(char *str, char *base1, char *base2)
{
	int	i;
	int	base1_bool;
	int	base2_bool;
	int	nb;

	nb = 0;
	i = 0;
	if (!str)
		return (0);
	base1_bool = ft_is_in_base(str[i], base1);
	base2_bool = ft_is_in_base(str[i], base2);
	while ((base1_bool > -1 || base2_bool > -1) && str[i])
	{
		if (base1_bool > 0)
			nb = nb * ft_strlen2(base1) + (base1_bool);
		else if (base2_bool > 0)
			nb = nb * ft_strlen2(base2) + (base2_bool);
		base1_bool = ft_is_in_base(str[i], base1);
		base2_bool = ft_is_in_base(str[i], base2);
		i++;
	}
	return (free(str), nb);
}
