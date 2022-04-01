/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:36:34 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/01 18:38:59 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	valid_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->col)
	{
		if (game->map[0][y] != '1' || game->map[game->row - 1][y] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (x < game->row)
	{
		if (game->map[x][0] != '1' || game->map[x][game->col - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	valid_sign(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (!(game->map[y][x] == 'P' || game->map[y][x] == 'E' || \
				game->map[y][x] == 'C' || game->map[y][x] == '0' || \
				game->map[y][x] == '1'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	exist_sign(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'P')
				game->player.stat++;
			if (game->map[y][x] == 'C')
				game->colcnt++;
			if (game->map[y][x] == 'E')
				game->exit.count++;
			x++;
		}
		y++;
	}
	if (game->player.stat != 1 || game->colcnt == 0 || game->exit.count == 0)
		return (0);
	return (1);
}

int	valid_table(t_game *game)
{
	if (!valid_wall(game) || !valid_sign(game) || !exist_sign(game))
		return (0);
	return (1);
}
