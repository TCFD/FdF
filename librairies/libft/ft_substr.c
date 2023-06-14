/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbp15 <zbp15@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:06:09 by rciaze            #+#    #+#             */
/*   Updated: 2023/02/22 12:27:59 by zbp15            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	char				*str;

	if (!s)
		return (NULL);
	if (len == 0 || (size_t) start > ft_strlen((char *) s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *) s) - start)
		len = ft_strlen((char *)s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i - start < (unsigned int)(len) && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

/* int	main(void)
{
	printf("%s", ft_substr("tripouille", 100, 1));
} */
