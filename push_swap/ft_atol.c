/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:43:35 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/13 18:40:49 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isspace(const char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'\
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int			i;
	long		sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (my_isspace(str, i))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 999999999999 && sign == 1)
			return (-1);
		if (result > 999999999999 && sign == -1)
			return (0);
		i++;
	}
	return (result * sign);
}
