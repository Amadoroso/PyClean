
#include "pyclean.h"

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *join(char *s1, char *s2)
{
	char *joined_str;
	int i;

	joined_str = calloc(ft_strlen(s1) + ft_strlen(s2) + 2, sizeof(char));
	i = 0;
	while (*s1)
	{
		*(joined_str + i) = *s1;
		i++;
		s1++;
	}
	*(joined_str + i) = '/';
	i++;
	while (*s2)
	{
		*(joined_str + i) = *s2;
		i++;
		s2++;
	}
	return (joined_str);

}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int	ft_strcmp(char *s1, char *s2)
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
	int i;

	i = 0;
	while (*(*s + i))
	{
		if (*(*s + i) >= 'A' && *(*s + i) <= 'Z')
			*(*s + i) = *(*s + i) + 32;
		i++;
	}
}

size_t	check_answer(char *buffer)
{
	uncap(&buffer);
	if (!ft_strcmp(buffer, "y"))
		return (1);
	else if (!ft_strcmp(buffer, "n"))
		return (0);
	else if (!ft_strcmp(buffer, "\n"))
		return (0);
	else
		return (0);
}
