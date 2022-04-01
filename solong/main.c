/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:21:30 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/01 15:22:54 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_exit(void)
{
	exit(0);
}

void	error_exit(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	input_key(t_game *game, int keycode)
{
	change_map(game, keycode);
	draw_map(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		input_key(game, keycode);
	game->player.count++;
	ft_putnbr_fd(game->player.count, 1);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Correct usage:./so_long [MAP_FILE].ber");
	if (!init_game(&game, argv[1]))
		error_exit("ERROR\nwrong row size");
	if (!valid_table(&game))
		error_exit("ERROR\nnot valid table");
	draw_map(&game);
	mlx_hook(game.win, KEY_EVENT_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, KEY_EVENT_EXIT, 0, &close_exit, 0);
	mlx_loop(game.mlx);
	return (0);
}
