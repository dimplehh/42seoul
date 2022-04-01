/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:30:45 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/12/04 14:52:26 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	void	ft_input_char(int *str_cnt, char **str, int demical, int *cpid)
{
	if (*str_cnt == 0)
		*str = (char *)ft_calloc(10000, sizeof(char));
	if (!(*str))
		return ;
	if (demical == 0)
	{
		if (*cpid == 0)
		{
			kill(ft_atoi(*str), SIGUSR1);
			*cpid = 1;
			*str_cnt = 0;
		}
		else
		{
			ft_putendl_fd(*str, 1);
			*cpid = 0;
		}
		free(*str);
		*str_cnt = 0;
	}
	else
		(*str)[(*str_cnt)++] = demical;
}

void	ft_handler(int signum)
{
	static int	count = 7;
	static char	*str;
	static int	demical = 0;
	static int	str_cnt = 0;
	static int	cpid = 0;

	if (signum == 31)
		demical += 1 << count;
	count--;
	if (count == -1)
	{
		ft_input_char(&str_cnt, &str, demical, &cpid);
		demical = 0;
		count = 7;
	}
}

int	main(void)
{
	int	id;

	id = (int)(getpid());
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		usleep(50);
}
