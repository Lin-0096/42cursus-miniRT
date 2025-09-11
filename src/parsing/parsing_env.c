#include "miniRT.h"
#include "parsing.h"

void get_a_light(char *line, t_scene *scene)
{
	char	**phases;
	char	**colors;

	scene->ambient_light = malloc(sizeof(t_a_light));
	if (!scene->ambient_light)
	{
		ft_putstr_fd("malloc failure inside t_scene\n", 1);
		return ;
	}
	ft_bzero(scene->ambient_light, sizeof(t_a_light));
	phases = ft_split(line, ' ');
	if (!phases)
		return; //need to have error msgs???
	colors = ft_split(phases[2], ',');
	if (!colors)
		return; //need to have error msgs???	
	scene->ambient_light->ratio = ft_atoi_float(phases[1]); // I need a atoi for floats here
	scene->ambient_light->r = ft_atoi((const char *)colors[0]);
	scene->ambient_light->g = ft_atoi((const char *)colors[1]);
	scene->ambient_light->b = ft_atoi((const char *)colors[2]);
}

void get_camera(char *line, t_scene *scene)
{
	char	**phases;
	char	**vec_1;
	char	**vec_2;

	scene->cam = malloc(sizeof(t_camera));
	if (!scene->cam)
	{
		ft_putstr_fd("malloc failure inside t_scene\n", 1);
		return ;
	}
	ft_bzero(scene->cam, sizeof(t_camera));
	phases = ft_split(line, ' ');
	if (!phases)
		return; //need to have error msgs???
	vec_1 =  ft_split(phases[1], ',');
	vec_2 =  ft_split(phases[2], ',');
	if (!vec_1 || !vec_2)
	{
		ft_putstr_fd("malloc failure inside t_scene\n", 1);
		return ;
	}
	ft_filling_vec(vec_1, &scene->cam->v_point);
	ft_filling_vec(vec_2, &scene->cam->v_orien);
	scene->cam->fov = ft_atoi((const char *)phases[3]);
}

// static void get_light(char *line, t_scene *scene)
// {

// }

