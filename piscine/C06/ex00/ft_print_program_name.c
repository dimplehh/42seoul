/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:18:47 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/11 20:21:34 by hyunhlee         ###   ########.fr       */
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

void	ft_print_program_name(char *argv)
{
	write(1, argv, ft_strlen(argv));
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc > 0)
		ft_print_program_name(argv[0]);
	return (0);
}
