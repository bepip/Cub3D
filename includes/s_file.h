#ifndef S_FILE_H
# define S_FILE_H

typedef struct s_file
{
	char	**cp_file;
	char	**map;
	int		width;
	int		height;
	int		player;
	int		so;
	int		no;
	int		ea;
	int		we;
	int		f;
	int		c;
	int		map_ind;
	char	*tex_no;
	char	*tex_so;
	char	*tex_ea;
	char	*tex_we;
	int		f_rgb[3];
	int		c_rgb[3];
}			t_file;

int			init_map(t_file *file);
int			init_file(t_file *data);
void		free_file(t_file *filep);
int			check_file(t_file *data);
void		display_file(t_file f);
int			copy_file(char *file, t_file *file_p);
int			set_variable(t_file *file);
int			set_cardinal_points(t_file *file, char **tab);
void		free_cardinals(t_file *file);
int			check_textures(char *str);
int			is_map_valid(t_file *file);
int			is_valid_row(t_file *file);
int			is_valid_col(t_file *file);
int			check_player(t_file *file);
int			check_extension(char *filename, char *ext);
#endif
