/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:25:08 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/13 15:02:45 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

	i = 0;
	d_len = (unsigned int)ft_strlen(dst);
	s_len = (unsigned int)ft_strlen(src);
	while (*dst)
		dst++;
	while (*src && (i + 1 + d_len < dstsize))
	{
		*dst++ = *src++;
		++i;
	}
	*dst = 0;
	if (dstsize < d_len)
		return (s_len + dstsize);
	else
		return (s_len + d_len);
}
