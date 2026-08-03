
#include "pyclean.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

size_t	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	uncap(char **s)
{
	while (**s)
	{
		if (**s >= 'A' && **s <= 'Z')
			**s = **s + 32;
		s++;
	}
}

size_t	check_answer(char *buffer)
{
	uncap(&buffer);
	if (!strcmp(buffer, "y"))
		return (1);
	else if (!strcmp(buffer, "n"))
		return (0);
	else if (!strcmp(buffer, "\n"))
		return (0);
	else
		return (0);
}
