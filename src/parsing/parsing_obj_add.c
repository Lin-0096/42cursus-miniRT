#include "miniRT.h"
#include "parsing.h"

bool	add_obj_to_scene(t_scene *scene, t_obj_type type, void *data)
{
	t_object	*obj;
	t_object	*tmp;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (false);
	obj->type = type;
	obj->data = data;
	obj->next = NULL;
	if (!scene->objects)
		scene->objects = obj;
	else
	{
		tmp = scene->objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
	return (true);
}
