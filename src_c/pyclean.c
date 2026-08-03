
#include "pyclean.h"

char	*pyclean()
{
	char *buffer;
	ssize_t read_rtrn;

	buffer = calloc(2, sizeof(char));
	if (!buffer)
		return NULL;
	write(1, "==== Welcome to PyClean ====\n\n", 31);
	write(1, "Are you sure you want to purge all __pycache__ / .mypy_cache from the current dir? [y/n]: ", 91);
	read_rtrn = read(0, buffer, 2);
	if (read_rtrn == -1)
		return(free(buffer), NULL);
	*(buffer + 1) = 0;
	if (!check_answer(buffer))
		return (free(buffer), NULL);
	free(buffer);
	return ("ABC");
}


int		main()
{
	if (!pyclean())
	{
		ft_putstr("Invalid answer, aborting...");
		return (0);
	}
	return (0);
}