/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:50:24 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/13 23:53:54 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	if (f(tab[0], tab[1]) >= 0)
	{
		while (i < length)
		{
			if (f(tab[i - 1], tab[i]) < 0)
				return (0);
			i++;
		}
	}
	i = 1;
	if (f(tab[0], tab[1]) <= 0)
	{
		while (i < length)
		{
			if (f(tab[i - 1], tab[i]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
