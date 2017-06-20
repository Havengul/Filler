#include <stdio.h>
#include "libft/libft.h"

int		main(void)
{
	char    *str;
	FILE *f = fopen("log.txt", "w");
	int     first = 0;

	while (get_next_line(0, &str) == 1)
	{
		fprintf(f, "%s\n", str);
		if (str == NULL)
			first++;
		if (first > 0)
			break;
	}
	fprintf(f, "----------------------------------------------\n");
	fclose(f);
	printf("2 1");
	return (0);
}
