/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:36:28 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/13 10:38:23 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *array;
	int bound;

	i = 0;
	bound = max - min;
	if (min >= max)
		return (0);
	if (!(array = malloc((bound) * sizeof(int))))
		return (0);
	while (i < bound)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
