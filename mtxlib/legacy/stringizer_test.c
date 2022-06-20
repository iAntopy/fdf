
#define SHAPE_STR(rows, cols) ({(cols > 0) ? ("<"#rows" x "#cols">"):("<"#rows" x 1>");})

#include <stdio.h>

int	main()
{
	printf(SHAPE_STR(4, 0));
	return (0);
}
