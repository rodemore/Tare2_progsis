
#include "funciones.h"

void print_help(char *command)
{
	printf("Programa en C ejemplo, imprime argumentos ingresados en consola.\n");
	printf("uso:\n %s [-i] [-e] [arg 1] [arg 2] ... [arg n]\n", command);
	printf(" %s -h\n", command);
	printf("Opciones:\n");
	printf(" -h\t\t\tAyuda, muestra este mensaje\n");
    printf(" -l\t\t\tMuestra conteo de líneas\n");
	printf(" -w\t\t\tMuestra conteo de palabras\n");
    printf(" -m\t\t\tMuestra conteo de caracteres\n");
    

    
}

int contar_palabras(FILE *archivo){
	int nw = -1;
	char texto[MAXWORD];
	while (fscanf(archivo, "%s", texto)==1){
		nw +=1;
	}
	if (nw == -1){
		return nw;
	}
	return nw+=1;
}


//Funcion para contar caracteres

int contar_caracteres(FILE *archivo)
{
	int nc = 0;
	char texto[MAXWORD];
	while (fscanf(archivo, "%s", texto)==1){
        nc += 1;
		nc += strlen(texto);

	}

	return nc;
}

int contar_lineas(FILE *archivo)
{
	int nl = 0;
	char texto[MAXWORD];
	while (fgets(texto, 50,archivo)){
        nl += 1;
	}

	return nl;
}

