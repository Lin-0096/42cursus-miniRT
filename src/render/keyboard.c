#include    "miniRT.h"
#include    "render.h"
#include    "parsing.h"

void	close_window(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	ft_free_scene(scene);
}

// close window from keyboard
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(scene);
}