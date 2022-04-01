/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:53:55 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/24 15:54:20 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	printf_c(char **buf, int arg)
{
	int i;

	i = 0;
	while ((*buf)[i] != 0)
		i++;
	(*buf)[i] = arg;
	return ('c');
}
