#ifndef SOLONG_H
# define SOLONG_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_EXIT 17
# define KEY_ESC 53

# define W 13
# define A 0
# define S 1
# define D 2

# define TILE_SIZE 64

typedef struct s_data {
	void	*img;
	int		width;
	int		height;
	int		*data;
}				t_data;

typedef struct s_player {
	int		x;
	int		y;
	t_data	data;
	int		count;
	int		stat;
}				t_player;

typedef struct s_exit {
	int	x;
	int	y;
	int	stat;
	int	count;
}				t_exit;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	int			row;
	int			col;
	int			colcnt;
	t_data		img;
	t_player	player;
	t_exit		exit;
}				t_game;

int		init_game(t_game *game, char *argv);
void	draw_map(t_game *game);
void	change_map(t_game *game, int keycode);
int		valid_table(t_game *game);

#endif
