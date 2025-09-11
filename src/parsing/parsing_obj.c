#include "miniRT.h"
#include "parsing.h"

void get_sphere(char *line, t_scene *scene)
{
	char	**phases;
	char	**vec_1;
	char	**vec_2;

	scene->sp = malloc(sizeof(t_sphere));
	if (!scene->sp)
	{
		ft_putstr_fd("malloc failure inside t_scene\n", 1);
		return ;
	}
	ft_bzero(scene->sp, sizeof(t_sphere));
	phases = ft_split(line, ' ');
	if (!phases)
		return; //need to have error msgs???
	vec_1 = ft_split(phases[1], ',');
	vec_2 = ft_split(phases[3], ',');
	if (!vec_1 || !vec_2)
	{
		ft_putstr_fd("malloc failure inside t_scene\n", 1);
		return ;
	}
	ft_filling_vec(vec_1, &scene->sp->sp_center);
	scene->sp->dia = ft_atoi_float(phases[2]);
	scene->sp->r = ft_atoi((const char *)vec_2[0]);
	scene->sp->g = ft_atoi((const char *)vec_2[1]);
	scene->sp->b = ft_atoi((const char *)vec_2[2]);

}

// void get_plane(char *line, t_scene *scene)
// {

// }

// void get_cylinder(char *line, t_scene *scene)
// {

// }