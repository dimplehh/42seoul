/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:10:39 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/13 19:55:30 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*newdst;
	const char	*newsrc;
	size_t		i;

	i = 0;
	newdst = dst;
	newsrc = src;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		if (newsrc[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
