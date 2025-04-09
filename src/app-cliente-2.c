#include <stdio.h>

#include "claves.h"

#define VAL2_MAX 32

// Intentar modificar un archivo con un N_value2 no válido
int main(int argc, char *argv[]) {
	destroy();

	double valores[VAL2_MAX + 1];
	for (int i = 0; i <= VAL2_MAX; i++) {
		valores[i] = i;
	}

	struct Coord coords = {3, 4};
	set_value(1, "set", 2, valores, coords);

	printf("%d\n", modify_value(1, "modify", VAL2_MAX + 1, valores, coords));
}
