
#include "../../includes/cub3d.h"

int check_textures(t_file *file)
{
    int fd;

    fd = open(file->no, O_RDONLY);
    if (fd < 0)
    {
        ft_fprintf(2, "Error\nOn opening the file\n");
        close(fd);
        return (FAILURE);
    }
    close(fd);
}
