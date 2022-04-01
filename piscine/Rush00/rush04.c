/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:24:16 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/03/28 14:49:37 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush1(int x, int y);
void	rush2(int x, int y);
void	rush3(int x, int y);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= y)
	{
		if (j == 1)
		{
			rush1(x, y);
		}
		else if (j >= 2 && j < y)
		{
			i = 1;
			rush2(x, y);
		}
		else
		{
			i = 1;
			rush3(x, y);
		}
		j++;
	}
}

void	rush1(int x, int y)
{
	int i;

	i = 1;
	ft_putchar('A');
	if (x > 1)
	{
		while (i < x - 1)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('C');
	}
	write(1, "\n", 2);
}

void	rush2(int x, int y)
{
	int i;

	i = 1;
	ft_putchar('B');
	if (x > 1)
	{
		while (i < x - 1)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
	}
	write(1, "\n", 2);
}

void	rush3(int x, int y)
{
	int i;

	i = 1;
	ft_putchar('C');
	if (x > 1)
	{
		while (i < x - 1)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('A');
	}
	write(1, "\n", 2);
}
