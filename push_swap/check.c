/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:43:26 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/27 11:45:28 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_number(char *argv)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(argv))
	{
		if (!ft_isdigit(argv[j]))
			if (!(argv[0] == '+' || argv[0] == '-') || \
			((argv[0] == '+' || argv[0] == '-') && (int)ft_strlen(argv) == 1))
				return (0);
		j++;
	}
	return (1);
}

int	is_int(char	*argv)
{
	if (ft_atol(argv) != ft_atoi(argv))
		return (0);
	return (1);
}

int	check(int argc, char **argv, t_deque *a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	j = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split[0])
			return (0);
		while (j < ft_col(argv[i], ' '))
		{
			if (!is_number(split[j]) || !is_int(split[j]))
				return (0);
			dq_add_last(a, ft_atoi(split[j]));
			j++;
		}
		m_free((const char **)split, j);
		j = 0;
		i++;
	}
	return (1);
}
