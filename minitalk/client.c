/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:30:57 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/12/03 15:49:34 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	send_null(int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(c, SIGUSR1);
		usleep(50);
		i++;
	}
}

void	ten_to_two(int c, char *n)
{
	int	a;
	int	i;

	while (*n != 0)
	{
		a = 128; //1000000
		i = 0;
		while (i < 8)
		{
			if ((a & (int)*n) == a)
				kill(c, SIGUSR2);
			else
				kill(c, SIGUSR1);
			a >>= 1;
			usleep(50);
			i++;
		}
		n++;
	}
	send_null(c);
}

void	ft_handler(int signum)
{
	if (signum == 30)
		ft_putendl_fd("message delievered!", 1);
	else
		ft_putendl_fd("Wrong PID!", 1);
}

int	main(int argc, char *argv[])
{
	int		id;
	int		server_pid;
	char	*str;

	id = (int)(getpid());
	signal(SIGUSR1, ft_handler);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_putendl_fd("Error: wrong PID", 1);
			return (0);
		}
		str = ft_itoa(id);
		ten_to_two(server_pid, str);
		free(str);
		ten_to_two(server_pid, argv[2]);
		return (0);
	}
	ft_putendl_fd("Error: ./client [server pid] \"text to send\"", 1);
	return (0);
}
