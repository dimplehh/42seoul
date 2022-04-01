/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:09:37 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/13 21:40:49 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *str;
	int i;

	i = 0;
	if (!(str = malloc(sizeof(*str) * length)))
		return (NULL);
	while (i < length)
	{
		str[i] = f(tab[i]);
		i++;
	}
	return (str);
}
