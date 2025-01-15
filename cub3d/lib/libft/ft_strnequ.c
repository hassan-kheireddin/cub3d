
#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	while (*s1 && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}
