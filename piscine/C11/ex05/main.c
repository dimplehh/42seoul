/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:13:49 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/15 11:47:40 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_calc(int n1, char *sign, int n2)
{
	int (*f[5])(int, int);

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_mul;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	if (*sign == '+')
		ft_putnbr(f[0](n1, n2));
	if (*sign == '-')
		ft_putnbr(f[1](n1, n2));
	if (*sign == '*')
		ft_putnbr(f[2](n1, n2));
	if (*sign == '/')
		ft_putnbr(f[3](n1, n2));
	if (*sign == '%')
		ft_putnbr(f[4](n1, n2));
	write(1, "\n", 1);
}

void	ft_doop(char *n1, char *sign, char *n2)
{
	int		n_atoi1;
	int		n_atoi2;

	n_atoi1 = ft_atoi(n1);
	n_atoi2 = ft_atoi(n2);
	if (sign[1] == '\0' && (sign[0] == '+' || sign[0] == '-'
				|| sign[0] == '/' || sign[0] == '*' || sign[0] == '%'))
	{
		if (sign[0] == '/' && n_atoi2 == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
		if (sign[0] == '%' && n_atoi2 == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
		ft_calc(n_atoi1, sign, n_atoi2);
	}
	else
		write(1, "0\n", 2);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		ft_doop(argv[1], argv[2], argv[3]);
	}
	return (0);
}
