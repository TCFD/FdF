/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbp15 <zbp15@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:35:18 by rciaze            #+#    #+#             */
/*   Updated: 2023/02/22 12:26:00 by zbp15            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*end_search(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		boolean;
	int		count;

	count = 0;
	i = ft_strlen((char *)s1) - 1;
	while (s1[i])
	{
		boolean = 0;
		j = -1;
		while (set[++j] && !boolean)
		{
			if (set[j] == s1[i])
			{
				boolean = 1;
				count++;
			}
		}
		if (!boolean)
			break ;
		else
			i--;
	}
	return (ft_substr(s1, 0, ft_strlen((char *)s1) - count));
}

char	*start_search(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		boolean;

	i = -1;
	while (s1[++i])
	{
		boolean = 0;
		j = -1;
		while (set[++j] && !boolean)
		{
			if (set[j] == s1[i])
				boolean = 1;
		}
		if (!boolean)
			break ;
	}
	return (end_search(s1 + i, set));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	return (start_search(s1, set));
}

/* int	main(void)
{
	printf("%s\n", ft_strtrim("   axx   axx", "x "));
} */