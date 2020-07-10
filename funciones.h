#include <stdio.h>
#include <string.h>
#define MAXWORD 150

/**
 * Función contar_palabras cuenta el número de palabras en un archivo, asume que las palabras están
 * separadas por espacios o salto de línea "\n".
 *
 * @param archivo Puntero al archivo, asumir solo lectura.
 *
 * @return Número de palabras en el archivo. -1 si hubo error.
 */
void print_help(char *command);
int contar_palabras(FILE *archivo);
int contar_caracteres(FILE *archivo);
int contar_lineas(FILE *archivo);