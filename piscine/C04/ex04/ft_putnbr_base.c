/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:05:38 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/08 17:37:08 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strchr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		ft_overlap(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_long(long long nbr, char *base)
{
	if (nbr >= (long long)ft_strlen(base))
		ft_putnbr_long(nbr / (long long)ft_strlen(base), base);
	write(1, &(base[nbr % (long long)ft_strlen(base)]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long n;

	n = nbr;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1
			|| ft_strchr(base) || ft_overlap(base))
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_long(n * (-1), base);
	}
	else
	{
		if (nbr >= ft_strlen(base))
			ft_putnbr_base(nbr / ft_strlen(base), base);
		write(1, &(base[nbr % ft_strlen(base)]), 1);
	}
}
