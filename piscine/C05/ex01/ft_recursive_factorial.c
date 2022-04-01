/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:05:19 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/13 09:40:46 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int n_over;

	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	n_over = nb * ft_recursive_factorial(nb - 1);
	return (n_over);
}
