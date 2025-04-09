#include <stdio.h>

#include "claves.h"

#define VAL1_LENGTH 256


// Intentar hacer un get_value con una clave que no existe
int main(int argc, char *argv[]) {
	destroy();

	char string[VAL1_LENGTH];
	int nval2;
	double valores[2];
	struct Coord coords;
	printf("%d\n", get_value(1, string, &nval2, valores, &coords));

	return 0;
}
