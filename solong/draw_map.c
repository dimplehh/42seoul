#include "solong.h"

void draw_player(t_game *game)
{
    int x;
	int y;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'P')
			{
				game->img.img = mlx_xpm_file_to_image(game->mlx, "image/fox.xpm", &game->img.width, &game->img.height);
				mlx_put_image_to_window(game->mlx, game->win, game->img.img, TILE_SIZE * x, TILE_SIZE * y);
                game->player.x = x;
                game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

void draw_portal(t_game *game)
{
    int x;
	int y;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'E')
			{
				game->img.img = mlx_xpm_file_to_image(game->mlx, "image/exit.xpm", &game->img.width, &game->img.height);
				mlx_put_image_to_window(game->mlx, game->win, game->img.img, TILE_SIZE * x, TILE_SIZE * y);
				game->exit.x = x;
                game->exit.y = y;
			}
			x++;
		}
		y++;
	}
}

void draw_collection(t_game *game)
{
    int x;
	int y;

	y = 0;
	game->colcnt = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'C')
			{
				game->img.img = mlx_xpm_file_to_image(game->mlx, "image/cookie.xpm", &game->img.width, &game->img.height);
				mlx_put_image_to_window(game->mlx, game->win, game->img.img, TILE_SIZE * x, TILE_SIZE * y);
				game->colcnt++;
			}
			x++;
		}
		y++;
	}
	if(game->colcnt == 0)
		game->exit.stat = 1;
}

void draw_bg(t_game *game)
{
    int x;
	int y;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == '1')
			{
				game->img.img = mlx_xpm_file_to_image(game->mlx, "image/wall.xpm", &game->img.width, &game->img.height);
				mlx_put_image_to_window(game->mlx, game->win, game->img.img, TILE_SIZE * x, TILE_SIZE * y);
			}
			else
			{
				game->img.img = mlx_xpm_file_to_image(game->mlx, "image/floor.xpm", &game->img.width, &game->img.height);
				mlx_put_image_to_window(game->mlx, game->win, game->img.img, TILE_SIZE * x, TILE_SIZE * y);
			}
			x++;
		}
		y++;
	}
}

void draw_map(t_game *game)
{
	draw_bg(game);
	draw_collection(game);
	draw_portal(game);
	draw_player(game);
}