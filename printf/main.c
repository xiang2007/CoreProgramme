#include "ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argv[1][0] == 'c')
	{
		//Printing chacarter &c
		ft_printf("Character: %c\n",'c');
		printf("Character: %c\n",'c');

		ft_printf("\nPrint Newline: %c",'\n');
		printf("Print Newline: %c",'\n');

		ft_printf("\nft_print number: %c\n",'1');
		printf("Print number: %c\n", '1');

		char c = 99;
		ft_printf("\nft_printf ascii: %c\n", c);
		printf("Printf ascii: %c\n", c);

		ft_printf("\nft_printf null: %c\n", '\0');
		printf("Printf null %c\n\n", '\0');

		char str[] = "Hello World";
		int	index = 0;
		ft_printf("%s", "ft_printf array: ");
		while (str[index])
			ft_printf("%c", str[index++]);
		index = 0;

		ft_printf("\n%s", "printf array: ");
		while (str[index])
			printf("%c", str[index++]);
		printf("\n");
	}
	if (argc[1][0] == 'd')
	{
		                                        
	}
}