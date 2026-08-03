
#include "pyclean.h"

void cleaner()
{
	DIR *current_dir;

	current_dir = opendir(".");
	
}

char	*pyclean()
{
	char *buffer;
	ssize_t read_rtrn;

	buffer = calloc(2, sizeof(char));
	if (!buffer)
		return NULL;
	putstr("==== Welcome to PyClean ====\n\n");
	putstr("Are you sure you want to purge all __pycache__ / .mypy_cache from the current dir? [y/n]: ");
	read_rtrn = read(0, buffer, 2);
	if (read_rtrn == -1)
		return(free(buffer), NULL);
	*(buffer + 1) = 0;
	if (!check_answer(buffer))
		return (free(buffer), NULL);
	cleaner();
	free(buffer);
	return ("ABC");
}

int	main()
{
	if (!pyclean())
	{
		ft_putstr("Invalid answer, aborting...");
		return (0);
	}
	return (0);
}