/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:52:18 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/03/31 01:26:25 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_logic(int n, int *t)
{
	int max;
	int i;

	i = n - 1;
	max = 9;
	while (t[i] == max)
	{
		max--;
		i--;
	}
	t[i]++;
	while (i < n)
	{
		t[i + 1] = t[i] + 1;
		i++;
	}
}

void	ft_print(int n, int *t)
{
	int i;

	i = 0;
	ft_putchar(',');
	ft_putchar(' ');
	while (i < n)
	{
		ft_putchar('0' + t[i]);
		i++;
	}
}

void	ft_first(int n, int *t)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0' + t[i]);
		i++;
	}
}

void	ft_print_comb(int n)
{
	int t[10];
	int i;

	i = 0;
	while (i < n)
	{
		t[i] = i;
		i++;
	}
	ft_first(n, t);
	while (t[n - 1] != 9 || t[0] != 10 - n)
	{
		if (t[n - 1] != 9)
		{
			t[n - 1]++;
		}
		else
		{
			ft_logic(n, t);
		}
		ft_print(n, t);
	}
}

int main(void)
{
	ft_print_comb(2);
}
