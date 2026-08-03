
#include "pyclean.h"

void	sub_cleaner(char *dir)
{
	struct dirent *entry;
	char *full_path;
	DIR *current_dir;

	current_dir = opendir(dir);
	if (!current_dir)
	{
		ft_putstr("Error, couldn't open the current directory...\n");
		return ;
	}
	while ((entry = readdir(current_dir)))
	{
		if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
        	continue;
		full_path = join(dir, entry->d_name);
		remove(full_path);
		free(full_path);
	}
	closedir(current_dir);
}

void cleaner(char *path)
{
	DIR *current_dir;
	char *full_path;
	struct dirent *entry;

	current_dir = opendir(path);
	if (!current_dir)
	{
		ft_putstr("Error, couldn't open the current directory...\n");
		return ;
	}
	while ((entry = readdir(current_dir)))
	{
		if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
            continue;
		full_path = join(path, entry->d_name);
		if (entry->d_type == DT_DIR)
		{
			if (!ft_strcmp(entry->d_name, "__pycache__") || !ft_strcmp(entry->d_name, ".mypy_cache"))
			{
				sub_cleaner(full_path);
				remove(full_path);
				printf("Sucessfully Removed: %s\n", full_path);
			}
			else
				cleaner(full_path); // Recursive
		}
		free(full_path);
	}
	closedir(current_dir);
}

char	*pyclean()
{
	char *buffer;
	ssize_t read_rtrn;

	buffer = calloc(2, sizeof(char));
	if (!buffer)
		return NULL;
	ft_putstr("==== Welcome to PyClean ====\n\n");
	ft_putstr("Are you sure you want to purge all __pycache__ / .mypy_cache from the current dir? [y/n]: ");
	read_rtrn = read(0, buffer, 2);
	if (read_rtrn == -1)
		return(free(buffer), NULL);
	*(buffer + 1) = 0;
	if (!check_answer(buffer))
		return (free(buffer), NULL);
	cleaner(".");
	free(buffer);
	return ("ABC");
}

int	main()
{
	if (!pyclean())
	{
		ft_putstr("Aborting...\n");
		return (0);
	}
	return (0);
}
