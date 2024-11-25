#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "s_error.h"
# include "s_file.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define SUCCESS 0
# define FAILURE 1

# define WIDTH 800
# define HEIGHT 800

typedef struct s_textures
{
	t_img		*img_no;
	t_img		*img_so;
	t_img		*img_ea;
	t_img		*img_we;
	int			f_rgb[3];
	int			c_rgb[3];
}				t_textures;

typedef struct s_game
{
	t_textures	textures;
	char		**map;
	int			row;
	int			col;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	char		dir;
	void		*mlx;
	t_img		*screen;
	void		*win;
	t_img		*img_game;
	t_img		*img_minimap;
}				t_game;

// init how to name functions? initGameAssets? or parseGameDAta? load_gameData?
int				init_game(t_game *game, char *filename);
int				init_game_data(t_game *gamep, t_file *data);
void			init_blank_game(t_game *gamep);
int				init_mlx(t_game *game, t_file *file);
void			free_game(t_game *game);
void			skip_newlines(t_file *file, int *i);

// key_handle
int				key_handle(int key, t_game *game);
int				close_window(t_game *game);
// error
void			err_msg(int err_code, char *msg);

// displays
void			display_game_data(t_game game);
#endif
