#include <string.h>
#include <stdio.h>

#include "claves.h"

#define VAL1_LENGTH 256


// Se crean 1000 tuplas, se modifican 500 y se recuperan todas
int main(int argc, char *argv[]) {
	destroy();

	for (int i = 0; i < 1000; i++) {
		double valores[2] = {i, 2 * i};
		struct Coord coords = {3 * i, 4 * i};
		set_value(i, "set", 2, valores, coords);
	}

	for (int i = 500; i < 1000; i++) {
		double valores[2] = {999 - i, 2 * (999 - i)};
		struct Coord coords = {3 * (999 - i), 4 * (999 - i)};
		modify_value(i, "modify", 2, valores, coords);
	}

	// Comprobamos que haya el mismo número de valores modificados que sin modificar
	int primera_suma[5] = {0, 0, 0, 0, 0};
	int segunda_suma[5] = {0, 0, 0, 0, 0};

	for (int i = 0; i < 500; i++) {
		char string[VAL1_LENGTH];
		int nval2;
		double valores[2];
		struct Coord coords;
		get_value(i, string, &nval2, valores, &coords);

		if (!strcmp(string, "set")) {
			primera_suma[0]++;
		}
		primera_suma[1] += (int) valores[0];
		primera_suma[2] += (int) valores[1];
		primera_suma[3] += coords.x;
		primera_suma[4] += coords.y;
	}

	for (int i = 500; i < 1000; i++) {
		char string[VAL1_LENGTH];
		int nval2;
		double valores[2];
		struct Coord coords;
		get_value(i, string, &nval2, valores, &coords);

		if (!strcmp(string, "modify")) {
			segunda_suma[0]++;
		}
		segunda_suma[1] += (int) valores[0];
		segunda_suma[2] += (int) valores[1];
		segunda_suma[3] += coords.x;
		segunda_suma[4] += coords.y;
	}

	for (int i = 0; i < 5; i++) {
		if (primera_suma[i] != segunda_suma[i]) {
			printf("Error en suma %d: %d en 500 primeros pero %d en restantes\n", i, primera_suma[i], segunda_suma[i]);
			destroy();
			return -1;
		}
	}
	printf("Las sumas coinciden\n");

	destroy();
	return 0;
}
