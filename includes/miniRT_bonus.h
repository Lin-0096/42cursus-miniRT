#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "miniRT.h"

// checkerboard, defalt yes true
# define USE_CHECKERBOARD 1
// specular strength
# define SPEC_K 0.5
// shininess
# define SPEC_SHININESS 16

t_color	final_color(t_scene *scene, t_hit_record rec);

#endif