#include "../../includes/cub3d.h"

int	ft_isempty_line(char *s);
static int	ft_isspace(int c);

void	skip_newlines(t_file *file, int *i)
{
	while (file->cp_file[*i] && ft_isempty_line(file->cp_file[*i]) == 1)
		++(*i);
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_isempty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}
