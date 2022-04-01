/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:59:05 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/07 00:06:32 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned	int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ft_strcmp(char *st1, char *st2)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(st1))
	{
		if (st1[i] > st2[i] || st1[i] < st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (st1[i] - st2[i]);
}

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	else if (n < 0)
		return (ft_strcmp(s1, s2));
	else
	{
		while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
		{
			if (s1[i] > s2[i] || s1[i] < s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
		return (0);
	}
}
