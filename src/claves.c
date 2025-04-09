#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/file.h>

#include "claves.h"

// Límites
#define KEY_LENGTH 11
#define VAL1_LENGTH 256
#define VAL2_MIN 1
#define VAL2_MAX 32


int write_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3) {
	// Abrir el archivo
	char ruta[PATH_MAX];
	sprintf(ruta, "../var/%d", key);
	FILE* archivo = fopen(ruta, "w");
	int fd = fileno(archivo);
	flock(fd, LOCK_EX);

	if (!archivo) {
		#ifdef DEBUG
			perror("write_value: no se ha podido abrir el archivo\n");
		#endif
		return -1;
	}

	// Volcar datos
	fprintf(archivo, "%s\n", value1);
	fwrite(&N_value2, sizeof(int), 1, archivo);
	fwrite(V_value2, sizeof(double), N_value2, archivo);
	fwrite(&value3, sizeof(struct Coord), 1, archivo);

	// Cerrar el archivo
	fclose(archivo);
	flock(fd, LOCK_UN);
	return 0;
}


int destroy() {
	// Abrir ../var
	DIR* directorio = opendir("../var");
	struct dirent* archivo;

	if (!directorio) {
		#ifdef DEBUG
			perror("destroy: no se ha podido abrir var\n");
		#endif
		return -1;
	}

	while ((archivo = readdir(directorio))) {
		// Eliminar todos los archivos del directorio
		if (!strcmp(archivo->d_name, ".") || !strcmp(archivo->d_name, "..")) {
			continue;
		}

		char ruta[PATH_MAX] = "../var/";
		strcat(ruta, archivo->d_name);

		if (unlink(ruta) == -1) {
			#ifdef DEBUG
				perror("destroy: no se ha podido borrar un archivo\n");
			#endif
			closedir(directorio);
			return -1;
		}
	}

	// Cerrar ../var
	closedir(directorio);
	return 0;
}


int set_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3) {
	// Comprobar que la clave no exista
	if (exist(key)) {
		#ifdef DEBUG
			perror("set_value: la clave ya existe\n");
		#endif
		return -1;
	}

	// Escribir datos
	return write_value(key, value1, N_value2, V_value2, value3);
}


int get_value(int key, char *value1, int *N_value2, double *V_value2, struct Coord *value3) {
	// Comprobar que la clave exista
	if (!exist(key)) {
		#ifdef DEBUG
			perror("get_value: la clave no existe\n");
		#endif
		return -1;
	}

	// Abrir el archivo
	char ruta[PATH_MAX];
	sprintf(ruta, "../var/%d", key);
	FILE* archivo = fopen(ruta, "r");
	int fd = fileno(archivo);
	flock(fd, LOCK_EX);

	if (!archivo) {
		#ifdef DEBUG
			perror("get_value: no se ha podido abrir el archivo\n");
		#endif
		return -1;
	}

	// Leer los datos
	char sanitizer[VAL1_LENGTH + 1]; // Variable auxiliar para poder eliminar el \n de fgets hasta cuando strlen(value1) == 255
	if (!fgets(sanitizer, VAL1_LENGTH, archivo)) {
		return -1;
	}
	sanitizer[strlen(sanitizer) - 1] = '\0'; // Eliminar el \n final de fgets
	strcpy(value1, sanitizer);

	if (fread(N_value2, sizeof(int), 1, archivo) < sizeof(int)) {
		return -1;
	}
	if (fread(V_value2, sizeof(double), * N_value2, archivo) < sizeof(double) * *N_value2) {
		return -1;
	}
	if (fread(value3, sizeof(struct Coord), 1, archivo) < sizeof(struct Coord)) {
		return -1;
	}

	// Cerrar el archivo
	fclose(archivo);
	flock(fd, LOCK_UN);
	return 0;
}


int modify_value(int key, char *value1, int N_value2, double *V_value2, struct Coord value3) {
	// Comprobar que la clave exista
	if (!exist(key)) {
		#ifdef DEBUG
			perror("modify_value: la clave no existe\n");
		#endif
		return -1;
	}

	// Escribir datos
	return write_value(key, value1, N_value2, V_value2, value3);
}


int delete_key(int key) {
	// Comprobar que la clave exista
	if (!exist(key)) {
		#ifdef DEBUG
			perror("delete_key: la clave no existe\n");
		#endif
		return -1;
	}

	// Borrar archivo
	char ruta[PATH_MAX];
	sprintf(ruta, "../var/%d", key);
	if (unlink(ruta) == -1) {
		#ifdef DEBUG
			perror("delete_key: no se ha podido borrar el archivo\n");
		#endif
		return -1;
	}

	return 0;
}


int exist(int key) {
	// Comprobar la existencia del archivo asociado
	char ruta[PATH_MAX];
	sprintf(ruta, "../var/%d", key);
	return !access(ruta, F_OK);
}
