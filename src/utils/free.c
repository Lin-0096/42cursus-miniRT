#include "miniRT.h"

void ft_free_scene(t_scene *scene)
{
    if (!scene)
        return;
    // Free spheres array if it exists
    if (scene->sp)
    {
        free(scene->sp);
        scene->sp = NULL;
        scene->sp_nbr = 0;
    }
    // free *pl and *cy later
    free(scene);
}