/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:33:24 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/01 15:33:28 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	player_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->exit.count)
	{
		if (game->player.x == game->exit.x[i] \
		&& game->player.y == game->exit.y[i])
			return (1);
		i++;
	}
	return (0);
}

void	player_move(t_game *game, int keycode)
{
	if (!player_exit(game))
		game->map[game->player.y][game->player.x] = '0';
	if (keycode == W && game->map[game->player.y - 1][game->player.x] != '1')
		game->player.y--;
	if (keycode == S && game->map[game->player.y + 1][game->player.x] != '1')
		game->player.y++;
	if (keycode == A && game->map[game->player.y][game->player.x - 1] != '1')
		game->player.x--;
	if (keycode == D && game->map[game->player.y][game->player.x + 1] != '1')
		game->player.x++;
	if (!player_exit(game))
		game->map[game->player.y][game->player.x] = 'P';
}

void	is_exit(t_game *game)
{
	if (game->exit.stat == 1 && player_exit(game))
		exit(0);
}

void	change_map(t_game *game, int keycode)
{
	player_move(game, keycode);
	is_exit(game);
}
