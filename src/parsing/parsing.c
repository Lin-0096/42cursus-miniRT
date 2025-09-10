#include "miniRT.h"
#include "parsing.h"

// static int parsing_line_return_sign(char *line)
// {


// }

//check if each line is valid,
//it has to start with the 6 identifies, it can be empty
//return 0 as error and 1 as valid line
static int identify_line(char *line)
{
	if (!line[0])
		return (0);
	if (ft_isspace(line[0]))
		return (1);
	else if (line[0] == 'A')
		return (1);
	else if (line[0] == 'C')
		return (1);
	else if (line[0] == 'L')
		return (1);
	if (line[0] && line[1])//I need a strncmp here
	{
		if (line[0] == 's' && line[1] == 'p')
			return (1);
		else if (line[0] == 'p' && line[1] == 'l')
			return (1);
		else if (line[0] == 'c' && line[1] == 'y')
			return (1);
	}
	return (0);
}

static int	precheck_av(int ac, char **av)
{
	char	*ext;

	if (ac != 2)
		return(err_msg_code("wrong ac nbr", 0));
	ext = ft_strrchr(av[1], '.');
	if (!ext || ft_strcmp(ext, ".rt") != 0)
		return (err_msg_code("wrong format", 0));
	return (1);
}

//return 0 as error and 1 as parsing success
int parsing(int ac, char **av)
{
    int fd;
	char   *line;
	
	if (precheck_av(ac, av))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (err_msg_code("open file failed", 0));
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);	//test printing, remove later
		//indentifila liken
		if (!identify_line(line))
			return (err_msg_code("invalide line in the file", 0));
		//parsing the line
		free (line);
		line = get_next_line(fd);
	}
	return (1);
}
