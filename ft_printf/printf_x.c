/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:00:29 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/24 16:04:18 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	printf_x(char p, char **buf, int arg)
{
	char	*newstr;

	while (**buf != 0)
		(*buf)++;
	if (arg < 0)
		newstr = ft_itoax(4294967296 + arg, p);
	else
		newstr = ft_itoax(arg, p);
	ft_memcpy(*buf, newstr, ft_strlen(newstr));
	free(newstr);
}
