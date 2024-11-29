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
# include <math.h>

# define SUCCESS 0
# define FAILURE 1

# define WIDTH 1280
# define HEIGHT 720

# define ROT_SPEED 0.05
# define MOVE_SPEED 0.15

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_textures
{
	t_img		*img_no;
	t_img		*img_so;
	t_img		*img_ea;
	t_img		*img_we;
	int			f_rgb;
	int			c_rgb;
}				t_textures;

typedef struct s_game
{
	t_textures	textures;
	char		**map;
	int			row;
	int			col;
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_img		*img_game;
	t_img		*img_minimap;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		dir_plane_x;
	float		dir_plane_y;
	float		dir_ray_x;
	float		dir_ray_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_x;
	float		delta_y;
	float		dist_perp;
	float		ratio;
	int			ray_pos_x;
	int			ray_pos_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_game;

// init how to name functions? initGameAssets? or parseGameDAta? load_gameData?
int		init_game(t_game *game, char *filename);
int		init_game_data(t_game *gamep, t_file *data);
void	init_blank_game(t_game *gamep);
int		init_mlx(t_game *game, t_file *file);
void	free_game(t_game *game);
void	skip_newlines(t_file *file, int *i);
int		set_player_dir(t_game *gamep, t_file *file);
int		init_raycast(t_game *game, t_file *file);

//mlx helper
void	draw_vertline(t_game *game, int x);

//render
int	render(t_game *game);
// key_handle
int		key_handle(int key, t_game *game);
int		close_window(t_game *game);
//keys
void	d_key(t_game *game);
void	w_key(t_game *game);
void	s_key(t_game *game);
void	a_key(t_game *game);
void	right_arrow_key(t_game *game);
void	left_arrow_key(t_game *game);
void	hide_show_mouse(t_game *game);
int	mouse_handle(int x, int y, t_game *game);
// error
void	err_msg(int err_code, char *msg);

// displays
void	display_game_data(t_game game);
#endif
