/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciaze <rciaze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:29:40 by rciaze            #+#    #+#             */
/*   Updated: 2023/03/08 15:42:32 by rciaze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(int **dest, int **src, size_t n)
{
	size_t	i;
	int		k;

	i = -1;
	while (++i < n)
	{
		k = -1;
		while (++k < 5)
				dest[i][k] = src[i][k];
	}
	return (dest);
}

/* int main()
{
	char d1[] = "Bonjour comment ca va ?", d2[] = "Bonjour comment ca va ?";

	ft_memcpy(&d1[10], &d1, 13);
	memcpy(&d2[10], &d2, 13);
	for ( int i = 0 ; i < 22 ; ++i )
		printf( "%c", d1[i] );
	printf("\n");
	for ( int i = 0 ; i < 22 ; ++i )
		printf( "%c", d2[i] );
	return 0;
}
 */