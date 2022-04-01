#include "solong.h"

void figure_rowcol(t_game *game, char *filename)
{
    int fd;
    int ret_value;
    char *line;

    line = NULL;
    if(fd > 0)
        fd = open(filename, O_RDONLY);
    ret_value = 1;
    while (ret_value == 1)
    {
        ret_value = get_next_line(fd, &line);
        game->col = strlen(line);
        game->row++;
    }
    free(line);//이런거때메 segfault가 뜨는거임.
    close(fd);
}

void malloc_table(t_game *game)
{
    int i;

    i = 0;
    game->map = malloc(sizeof(char *) * game->row);
    while(i < game->row)
    {
        game->map[i] = malloc(sizeof(char) * game->col);
        i++;
    }
}

void init_table(t_game *game, char *filename)
{
    int fd;
    int i;
    int ret_value;
    char *line;

    i = 0;
    line = NULL;
    if(fd > 0)
        fd = open(filename, O_RDONLY);
    ret_value = 1;
    while (ret_value == 1)
    {
        ret_value = get_next_line(fd, &line);
        strcpy(game->map[i], line);
        i++;
    }
    free(line);//이런거때메 segfault가 뜨는거임.
    close(fd);
}

void init_game(t_game *game, char *filename)
{
    game->player.count = 0;
    game->row = 0;
    game->exit.stat = 0;
    game->colcnt = 0;
    figure_rowcol(game, filename);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->col * TILE_SIZE, \
    game->row * TILE_SIZE, "solong");
    malloc_table(game);
    init_table(game, filename);
}