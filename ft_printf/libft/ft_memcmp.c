/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:17:39 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/13 15:02:17 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *news1;
	unsigned char *news2;

	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	while (n--)
	{
		if (*news1 > *news2 || *news1 < *news2)
			return (*news1 - *news2);
		news1++;
		news2++;
	}
	return (0);
}
