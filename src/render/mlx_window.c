#include    "miniRT.h"
#include    "render.h"
#include    "parsing.h"

//lin needs to uses this ??
// this is probably where our work overlapping each other
// I write this prototype here just as a starting point
// the color of each pixel will be calulated by lin
//0xAAFF1111, Transparency + rgb
void render_scene(t_scene *scene)
{
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT / 2)
        {
            mlx_put_pixel(scene->img, x, y, 0xAAFF1111);
            y++;
        }
        while (y < HEIGHT)
        {
            mlx_put_pixel(scene->img, x, y, 0xBBAAFF55);
            y++;
        }
        x++;
    }
}

static void	close_window(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	ft_free_scene(scene);
	exit(0);
}

// close window from keyboard
static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_window(scene);
}

//remove to render later
//mlx_init: 4th: full scree> true or false
bool	mlx_window(t_scene *scene)
{
	//this part need to take out later
	scene->mlx = mlx_init(WIDTH, HEIGHT, "miniRT_test", false);
	if (!scene->mlx)
    {   
        ft_putstr_fd("mlx_init failed\n", 1);
        return (false);
    }
	scene->img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
    if (!scene->img)
	{   
        ft_putstr_fd("mlx_new image failed\n", 1);
        return (false);
    }
	mlx_image_to_window(scene->mlx, scene->img, 0, 0);

    mlx_key_hook(scene->mlx, key_hook, scene); //Keyboard press/release
	mlx_close_hook(scene->mlx, close_window, scene);  //clicking red x

    render_scene(scene);
	mlx_loop(scene->mlx);

	//mlx_terminate(scene->mlx); this is in free_scene, so no need here.
	return (true);
}