#include "miniRT.h"
#include "parsing.h"

static void get_a_light(char *line, t_scene *scene)
{

}

static void get_camera(char *line, t_scene *scene)
{

}

static void get_sphere(char *line, t_scene *scene)
{

}

void parsing_line(char *line, t_scene *scene)
{
	if (ft_isspace(line[0]))
		return ;
	else if (line[0] == 'A')
		get_a_light(line, scene);
	else if (line[0] == 'C')
		get_camera(line, scene);
	// else if (line[0] == 'L')
	// 	get_light(line, scene);
	if (line[0] && line[1])//I need a strncmp here
	{
		if (line[0] == 's' && line[1] == 'p')
			get_sphere(line, scene);
		// else if (line[0] == 'p' && line[1] == 'l')
		// 	get_plane(line, scene);
		// else if (line[0] == 'c' && line[1] == 'y')
		// 	get_cylinder(line, scene);
	}
}