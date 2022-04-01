#include "solong.h"

void player_move(t_game *game, int keycode)
{
    if(!(game->player.x == game->exit.x && game->player.y == game->exit.y))
        game->map[game->player.y][game->player.x] = '0';
    if(keycode == KEY_W && game->map[game->player.y - 1][game->player.x] != '1')
        game->player.y--;
    if(keycode == KEY_S && game->map[game->player.y + 1][game->player.x] != '1')
        game->player.y++;
    if(keycode == KEY_A && game->map[game->player.y][game->player.x - 1] != '1')
        game->player.x--;
    if(keycode == KEY_D && game->map[game->player.y][game->player.x + 1] != '1')
        game->player.x++;
    if(!(game->player.x == game->exit.x && game->player.y == game->exit.y))
        game->map[game->player.y][game->player.x] = 'P';
}

void is_exit(t_game *game)
{
    if(game->exit.stat == 1 && (game->player.x == game->exit.x\
        && game->player.y == game->exit.y))
        exit(0);
}

void change_map(t_game *game, int keycode)
{
    player_move(game, keycode);
    is_exit(game);
}