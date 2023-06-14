/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:13 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/06 14:59:11 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (unsigned char)(c))
			return (i);
		i++;
	}
	return (ft_strlen((char *)str));
}

/* int	main(void)
{
	char s[] = "tripouille";

	printf("%s\n", ft_strchr(s, 'o' + 256));
	printf("%s\n", strchr(s, 'o' + 256));
} */