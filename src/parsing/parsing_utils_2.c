#include "miniRT.h"
#include "parsing.h"

static bool check_valid_color(char *color)
{
	while (*color)
	{
		if (!ft_isdigit(*color))
			return false;
		color++;
	}
	if (ft_atoi(color) > 255)
		return false;
	return true;
}

bool check_rgb(char **colors)
{
	printf("%s\n", "debug3");
    if (count_token_nbr(colors) != 3)
		return false;
    printf("%s\n", "debug3");
	while(*colors)
	{
		printf("%s\n", "debug3");
        if (!check_valid_color(*colors))
			return false;
		colors++;
	}
	return true;
}

void do_color(char **colors, t_color *rgb)
{
	rgb->r = ft_atoi(colors[0]);
	rgb->g  = ft_atoi(colors[1]);
	rgb->b  = ft_atoi(colors[2]);
}