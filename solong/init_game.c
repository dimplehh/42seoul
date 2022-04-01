/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:23:20 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/01 15:27:14 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	figure_rowcol(t_game *game, char *filename)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	if (fd > 0)
		fd = open(filename, O_RDONLY);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		game->col = ft_strlen(line);
		game->row++;
	}
	free(line);
	close(fd);
}

void	malloc_table(t_game *game)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->row);
	while (i < game->row)
	{
		game->map[i] = malloc(sizeof(char) * game->col);
		i++;
	}
}

int	init_table(t_game *game, char *filename)
{
	int		fd;
	int		i;
	int		length;
	int		ret_value;
	char	*line;

	i = 1;
	line = NULL;
	if (fd > 0)
		fd = open(filename, O_RDONLY);
	ret_value = get_next_line(fd, &line);
	length = ft_strlen(line);
	ft_strcpy(game->map[0], line);
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		if (length != ft_strlen(line))
			return (0);
		ft_strcpy(game->map[i++], line);
	}
	free(line);
	close(fd);
	return (1);
}

int	init_game(t_game *game, char *filename)
{
	game->player.count = 0;
	//game->player.stat = 0;
	game->row = 0;
	game->exit.stat = 0;
	game->colcnt = 0;
	figure_rowcol(game, filename);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * TILE_SIZE, \
			game->row * TILE_SIZE, "solong");
	malloc_table(game);
	return (init_table(game, filename));
}
