#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HEIGHT 600
# define EPSILON 1e-2
# define _USE_MATH_DEFINES

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

//self_defined header
# include "../libft/libft.h"
# include "MLX42/MLX42.h"
# include "parsing.h"
# include "raytrace.h"

//lib headers
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>      //open 

typedef struct s_render_data
{
	t_ray			ray;
	t_camera_view	view;
	t_hit_record	rec;
	t_color			c;
}	t_render_data;

/* ~~~~~~~~~~~~~~~~~~ VECTOR ~~~~~~~~~~~~~~~~~~ */
//vector
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_scale(t_vec3 a, float scalar);
float	vec_len(t_vec3 a);
t_vec3	vec_normalize(t_vec3 v);
float	vec_dot(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);

/* ~~~~~~~~~~~~~~~~~~ MLX ~~~~~~~~~~~~~~~~~~ */
//mlx_window.c			4/5
bool	mlx_window(t_scene *scene);
// keyboard.c			5/5	close by clicking x and 3 types of keyboard controk
void	close_window(void *param);
void	key_hook(mlx_key_data_t keydata, void *param);
//update_scene.c		4/5
void	change_move(t_scene *scene, t_vec3 move);
void	change_scale(t_scene *scene, float scale);
void	change_rotation(t_scene *scene, t_vec3 y_axis, float angle);

#endif
