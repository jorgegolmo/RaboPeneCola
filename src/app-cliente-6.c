#include <stdio.h>
#include <linux/limits.h>

#include "claves.h"

#define VAL1_LENGTH 256


// Intentar hacer un get_value con un archivo con formato no válido (val1 demasiado largo y resto de valores faltantes)
int main(int argc, char *argv[]) {
	destroy();

    FILE* archivo = fopen("../var/1", "w");
    fprintf(archivo, "En un lugar de la Mancha, de cuyo nombre no quiero acordarme, no ha mucho tiempo que vivía un hidalgo de los de lanza en astillero, adarga antigua, rocín flaco y galgo corredor. Una olla de algo más vaca que carnero, salpicón las más noches, duelos y quebrantos los sábados, lantejas los viernes, algún palomino de añadidura los domingos, consumían las tres partes de su hacienda. El resto della concluían sayo de velarte, calzas de velludo para las fiestas, con sus pantuflos de lo mesmo, y los días de entresemana se honraba con su vellorí de lo más fino. Tenía en su casa una ama que pasaba de los cuarenta, y una sobrina que no llegaba a los veinte, y un mozo de campo y plaza, que así ensillaba el rocín como tomaba la podadera. Frisaba la edad de nuestro hidalgo con los cincuenta años; era de complexión recia, seco de carnes, enjuto de rostro, gran madrugador y amigo de la caza. Quieren decir que tenía el sobrenombre de Quijada, o Quesada, que en esto hay alguna diferencia en los autores que deste caso escriben; aunque por conjeturas verosímiles se deja entender que se llamaba Quijana. Pero esto importa poco a nuestro cuento: basta que en la narración dél no se salga un punto de la verdad.");
    fclose(archivo);

	char string[VAL1_LENGTH];
	int nval2;
	double valores[2];
	struct Coord coords;
	printf("%d\n", get_value(1, string, &nval2, valores, &coords));

	return 0;
}
