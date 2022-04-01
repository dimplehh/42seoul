/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:09:27 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/11 13:06:31 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	return (i);
}

void	ft_rev_params(int argc, char **argv)
{
	int i;

	i = argc - 1;
	if (argc >= 2)
	{
		while (i >= 1)
		{
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "\n", 1);
			i--;
		}
	}
}

int		main(int argc, char **argv)
{
	ft_rev_params(argc, argv);
	return (0);
}
