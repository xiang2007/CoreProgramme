#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	return ;
}

int	main()
{
	ft_putstr("test");
}