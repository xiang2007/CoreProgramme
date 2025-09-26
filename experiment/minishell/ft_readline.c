#include "header.h"

int	main(void)
{
		char	*line_read;

		line_read = NULL;
		line_read = readline("Insert your line here: ");
		printf("prompt is %s\n", line_read);
		free (line_read);
		return (0);
}
