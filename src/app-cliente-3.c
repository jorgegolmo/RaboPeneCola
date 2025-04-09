#include <stdio.h>

#include "claves.h"


// Intentar hacer un set_value con una clave que ya existe
int main(int argc, char *argv[]) {
	destroy();

	double valores[2] = {1, 2};
	struct Coord coords = {3, 4};
	set_value(1, "set1", 2, valores, coords);

	printf("%d\n", set_value(1, "set2", 2, valores, coords));

	return 0;
}
