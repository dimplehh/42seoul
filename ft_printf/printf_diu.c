/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:57:19 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/24 15:58:47 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	printf_diu(char p, char **buf, int arg)
{
	char	*newstr;

	if (p == 'i' || p == 'd')
	{
		newstr = ft_itoa(arg);
		while (**buf != 0)
			(*buf)++;
		ft_memcpy(*buf, newstr, ft_strlen(newstr));
	}
	if (p == 'u')
	{
		while (**buf != 0)
			(*buf)++;
		if (arg < 0)
			newstr = ft_itoa(4294967296 + arg);
		else
			newstr = ft_itoa(arg);
		ft_memcpy(*buf, newstr, ft_strlen(newstr));
	}
	free(newstr);
}
