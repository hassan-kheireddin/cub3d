
#include "libft.h"

void	ft_putnbr(int n)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
	}
	if (l > 9)
		ft_putnbr(l / 10);
	ft_putchar(l % 10 + '0');
}
