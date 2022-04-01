/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buflen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:19:55 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/07/01 17:42:21 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int				ft_slen(t_options stat, int len)
{
	int n;

	n = len;
	if (stat.width == 0 && stat.dot == 0 && stat.type == 's')
		n = 0;
	if (stat.width != 0)
	{
		if (stat.dot >= 0 && stat.dot > len)
			n = len;
		if (stat.dot >= 0 && stat.dot <= len)
			n = stat.dot;
		if (n <= stat.width || (stat.dot == -1 && stat.width > len))
			n = stat.width;
	}
	else if (stat.width == 0 && stat.dot >= 0)
	{
		if (stat.dot <= len)
			n = stat.dot;
		else
			n = len;
	}
	return (n);
}

int				ft_buflen(char *buf, t_options stat)
{
	int n;

	n = ft_strlen(buf);
	if (n == 0 && stat.type == 'c')
		n = 1;
	if (stat.type == 's')
		return (ft_slen(stat, n));
	if (stat.width > (int)ft_strlen(buf))
		n = stat.width;
	if (stat.width == 0 && stat.dot == 0 && ft_strlen(buf) == 1
		&& buf[0] == '0' && (stat.type == 'd' || stat.type == 'u'
			|| stat.type == 'i' || stat.type == 'x' || stat.type == 'X'))
		n = 0;
	if ((stat.dot > (int)ft_strlen(buf)) && stat.dot > stat.width)
		n = stat.dot;
	if (buf[0] == '-' && stat.dot >= (int)ft_strlen(buf) &&
			stat.width <= stat.dot)
		n = stat.dot + 1;
	if (stat.width == 0 && stat.type == 'c')
		return (1);
	if (stat.type == 'c' && stat.width < stat.dot)
		return (stat.width);
	return (n);
}
